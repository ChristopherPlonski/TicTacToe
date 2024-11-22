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
	Board board = Board();
	Console console = Console(board);
	MarkerValidator markerValidator = MarkerValidator();
	GamemodeInfoHandler gamemodeInfoHandler = GamemodeInfoHandler();
	ArchetypeInfoHandler archetypeInfoHandler = ArchetypeInfoHandler();

	cout << "Welcome to Tic-Tac-Toe! \n";
	cout << endl; // Extra endl for prettiness.

	char playerMarkersArray[NUM_PLAYERS];

	for (int i = 0; i < NUM_PLAYERS; i++) {
		int playerNumber = i + 1;
		char playerMarker = markerValidator.get_valid_marker_for_human_player(playerNumber, playerMarkersArray, NUM_PLAYERS);

		playerMarkersArray[i] = playerMarker;
	}

	cout << endl; // Extra endl for prettiness.

	bool keepPlaying = true;

	while (keepPlaying) {
		GamemodeInfo::GamemodeType chosenGamemode = gamemodeInfoHandler.get_user_to_pick_gamemode_type();

		vector<Player*>* playersVector = new vector<Player*>();
		GameState gameState = GameState(board, *playersVector);

		if (chosenGamemode == GamemodeInfo::GamemodeType::REGULAR) {
			// Create regular players

			for (int i = 0; i < NUM_PLAYERS; i++) {
				int playerNumber = i + 1;
				Player* basicPlayer = new BasicPlayer(playerMarkersArray[i], playerNumber);

				playersVector->push_back(basicPlayer);
			}
		}
		else if (chosenGamemode == GamemodeInfo::GamemodeType::BATTLE) {
			// Have players choose their archetypes.
			cout << "Choose your archetypes! \n";

			for (int i = 0; i < NUM_PLAYERS; i++) {
				const int PLAYER_NUMBER = i + 1;
				cout << "* Player #" << PLAYER_NUMBER << ": \n";
				ArchetypeInfo userChosenArchetypeInfo = archetypeInfoHandler.get_user_to_pick_archetype();

				PlayerArchetypeBuilder playerArchetypeBuilder = PlayerArchetypeBuilder(board);

				Player* playerObjectFromChosenArchetype = playerArchetypeBuilder.create_player_object_from_archetype_info(
					userChosenArchetypeInfo, playerMarkersArray[i], PLAYER_NUMBER);

				playersVector->push_back(playerObjectFromChosenArchetype);
			}
		}
		else {
			// No implementation for this gamemode yet, not good.
			cerr << "ERROR: No implementation for GamemodeInfo with GamemodeType: " << ((int)chosenGamemode);
			throw runtime_error("No implementation for GamemodeInfo::GamemodeType.");
		}

		cout << endl; // Extra endl for prettiness.

		start_game(board, console, gameState, *playersVector);

		string userResponse;

		cout << "Would you like to continue playing? Type 'no' to stop. Type anything else to continue. ";
		getline(cin, userResponse);
		
		if (StringConverter::to_lowercase(userResponse) == "no") {
			keepPlaying = false;
		}
		else {
			board.clear_board();
		}

		// Delete players!
		for (int i = 0; i < NUM_PLAYERS; i++) {
			Player* player = playersVector->at(i);

			delete player;
		}

		delete playersVector;
	}
}

void Game::start_game(Board &board, Console &console, GameState &gameState, vector<Player*> &playersVector) {
	cout << "~~-~~ Starting Game ~~-~~\n\n";
	int currentPlayerIndex = 0;

	while (gameState.get_current_state() == GameState::State::InProgress) {
		Player* currentPlayer = playersVector.at(currentPlayerIndex);

		cout << console.display();
		cout << endl; // Extra endl for prettiness.

		//cout << "DEBUG: Getting move\n";
		Move userMove = get_valid_player_move(*currentPlayer, board);

		//cout << "Debug: Checking move\n";
		bool userDidMarkMove = userMove.get_optional_mark_position().has_value();

		if (userDidMarkMove) {
			int userMoveNumber = userMove.get_optional_mark_position().value();
			cout << "Player move: " << userMoveNumber << endl;
			board.mark_pos(userMoveNumber, currentPlayer->get_marker());
		}
		else if (userMove.used_turn_ending_ability()){
			cout << "Player used ability as turn." << endl;
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
	Move userValidMove;

	bool gotValidMove = false;

	while (!gotValidMove) {
		//cout << "DEBUG: In loop\n";
		Move playerMove = get_player_move(currentPlayer);
		//cout << "DEBUG: Loop 1 move: " << playerMove << endl;

		// TODO: Refactor validator result to use InvalidInput instead of string.
		MoveValidator::MoveValidationType moveValidatorResult = MoveValidator::is_move_valid(playerMove, board);

		bool moveWasValid = moveValidatorResult == MoveValidator::MoveValidationType::VALID_MOVE;

		if (moveWasValid) {
			gotValidMove = true;
			userValidMove = playerMove;
		}

		switch (moveValidatorResult)
		{
		case MoveValidator::MoveValidationType::VALID_MOVE:
			// Do nothing
			break;
		case MoveValidator::MoveValidationType::OUT_OF_BOARD_BOUNDS:
			cout << "Provided move (" << to_string(playerMove.get_optional_mark_position().value()) << ") is out of board bounds. Try again.\n";
			break;
		case MoveValidator::MoveValidationType::MARK_MOVE_SPACE_OCCUPIED:
			cout << "Tile at number: " << to_string(playerMove.get_optional_mark_position().value()) << " is already occupied. Try again.\n";
			break;
		case MoveValidator::MoveValidationType::MOVE_ERROR:
			// An error should have be thrown, so this might not even run?
			cerr << "ERROR: User move didn't mark position or use ability!\n";
			break;
		default:
			break;
		}
	}

	return userValidMove;
}

Move Game::get_player_move(Player& player)
{
	Move userMove;

	bool gotMove = false;

	while (!gotMove) {
		//cout << "DEBUG: In loop2 \n";
		cout << player.get_move_prompt_text();

		string userInput;
		getline(cin, userInput);

		pair<optional<Move>, InvalidInput*> userOptionalMove = player.try_get_move_from_input(userInput);
		//cout << "DEBUG: Loop 2 move: " << userOptionalMove.first.value() << endl;

		if (userOptionalMove.second != nullptr) {
			// An invalid input was made.
			cout << userOptionalMove.second->message() << " Try again." << endl;
		}
		else {
			// A move was made!
			userMove = userOptionalMove.first.value();
			gotMove = true;
		}

		// Make sure to delete the InvalidInput* after use!
		delete userOptionalMove.second;
	}

	return userMove;
}
