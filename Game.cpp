#include <iostream>

#include "Game.hpp"
#include "HumanPlayer.hpp"
#include "Settings.hpp"
#include "StringConverter.hpp"
#include "MoveValidator.hpp"

using namespace std;

void Game::start_game_loop()
{
	Board* board = new Board();
	Console console = Console(*board);
	Settings settings = Settings();

	cout << "Welcome to Tic-Tac-Toe! \n";

	vector<Player*>* playersVector = new vector<Player*>();

	for (int i = 0; i < NUM_PLAYERS; i++) {
		int playerNumber = i + 1;
		char playerMarker = settings.get_valid_marker_for_human_player(playerNumber, playersVector);

		HumanPlayer* newPlayer = new HumanPlayer(playerMarker, playerNumber);
		playersVector->push_back(newPlayer);
	}

	GameState gameState = GameState(*board, *playersVector);

	bool keepPlaying = true;

	while (keepPlaying) {
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
			cout << "User move: " << userMoveNumber << endl;
			board.mark_pos(userMoveNumber, currentPlayer->get_marker());
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