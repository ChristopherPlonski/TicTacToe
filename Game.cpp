#include <iostream>

#include "Game.hpp"
#include "BasicPlayer.hpp"
#include "MarkerValidator.hpp"
#include "StringConverter.hpp"
#include "MoveValidator.hpp"
#include "GamemodeInfoHandler.hpp"
#include "ArchetypeInfoHandler.hpp"
#include "PlayerArchetypeBuilder.hpp"

using namespace std;

void Game::start_game_loop()
{
	Board* board = new Board();
	Console console = Console(*board);
	MarkerValidator markerValidator = MarkerValidator();
	GamemodeInfoHandler gamemodeInfoHandler = GamemodeInfoHandler();

	cout << "Welcome to Tic-Tac-Toe! \n";

	vector<Player*>* playersVector = new vector<Player*>();

	for (int i = 0; i < NUM_PLAYERS; i++) {
		int playerNumber = i + 1;
		char playerMarker = markerValidator.get_valid_marker_for_human_player(playerNumber, playersVector);

		BasicPlayer* newPlayer = new BasicPlayer(playerMarker, playerNumber);
		playersVector->push_back(newPlayer);
	}

	GameState gameState = GameState(*board, *playersVector);

	bool keepPlaying = true;

	while (keepPlaying) {
		GamemodeInfo::GamemodeType chosenGamemode = gamemodeInfoHandler.get_user_to_pick_gamemode_type();

		if (chosenGamemode == GamemodeInfo::GamemodeType::REGULAR) {
			// Nothing special for regular gamemode
		}
		else if (chosenGamemode == GamemodeInfo::GamemodeType::BATTLE) {
			ArchetypeInfoHandler archetypeInfoHandler = ArchetypeInfoHandler();

			// Have players choose their archetypes.
			cout << "Choose your archetypes! \n";

			for (int i = 0; i < NUM_PLAYERS; i++) {
				const int PLAYER_NUMBER = i + 1;
				cout << "Player #" << PLAYER_NUMBER << ": \n";
				ArchetypeInfo::ArchetypeType userChosenArchetypeType = archetypeInfoHandler.get_user_to_pick_archetype_type();

				PlayerArchetypeBuilder playerArchetypeBuilder = PlayerArchetypeBuilder(*board);

				Player* playerObjectFromChosenArchetype = playerArchetypeBuilder.create_player_object_from_archetype_type(
					userChosenArchetypeType, PLAYER_NUMBER, playersVector->at(i)->get_marker());

				// TODO: test if this works! Tested. Does not work. Figure out a fix.
				delete[] playersVector->at(i);

				playersVector->at(i) = playerObjectFromChosenArchetype;
			}
		}
		else {
			// No implementation for this gamemode yet, not good.
			cerr << "ERROR: No implementation for GamemodeInfo with GamemodeType: " << ((int)chosenGamemode);
		}

		start_game(*board, console, gameState, *playersVector);

		string userResponse;

		cout << "Would you like to continue playing? Type 'no' to stop. Type anything else to continue. ";
		getline(cin, userResponse);
		
		if (StringConverter::to_lowercase(userResponse) == "no") {
			keepPlaying = false;
		}
		else {
			board->clear_board();
		}
	}
}

void Game::start_game(Board &board, Console &console, GameState &gameState, vector<Player*> &playersVector) {
	int currentPlayerIndex = 0;

	while (gameState.get_current_state() == GameState::State::InProgress) {
		Player* currentPlayer = playersVector.at(currentPlayerIndex);

		cout << console.display();

		Move userMove = get_valid_player_move(*currentPlayer, board);

		bool userDidMarkMove = userMove.get_optional_mark_position().has_value();

		if (userDidMarkMove) {
			int userMoveNumber = userMove.get_optional_mark_position().value();
			cout << "Player move: " << userMoveNumber << endl;
			board.mark_pos(userMoveNumber, currentPlayer->get_marker());
		}
		else if (userMove.used_turn_ending_ability()){
			cout << "Player used abiltiy as turn." << endl;
		}
		else {
			// There was some implementation that hasn't been made yet.
			cerr << "ERROR: No implementation for unique userMove." << endl;
		}

		// Set currentPlayer to next player
		if (currentPlayerIndex == playersVector.size() - 1) {
			currentPlayerIndex = 0;
		}
		else {
			currentPlayerIndex++;
		}
	}

	cout << console.display();
	cout << "Good game! ";

	switch (gameState.get_current_state())
	{
	case GameState::State::Draw:
		cout << "It was a draw. \n";
		break;
	case GameState::State::Player1Win:
		cout << "Player 1 (" << playersVector.at(0)->get_marker() << ") won!";
		break;
	case GameState::State::Player2Win:
		cout << "Player 2 (" << playersVector.at(1)->get_marker() << ") won!";
		break;
	default:
		cout << "Unknown result.";
		break;
	}

	cout << endl;
}

Move Game::get_valid_player_move(Player& currentPlayer, Board& board)
{
	Move userMove;

	bool gotValidMove = false;

	while (!gotValidMove) {
		userMove = currentPlayer.get_move();

		pair<bool, string> validatorResult = MoveValidator::is_move_valid(userMove, board);
		bool moveWasValid = validatorResult.first;
		string moveResultText = validatorResult.second;

		if (moveWasValid) {
			gotValidMove = true;
		}

		cout << moveResultText;
	}

	return userMove;
}