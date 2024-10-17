#include <iostream>

#include "Game.hpp"
#include "HumanPlayer.hpp"

using namespace std;

void Game::start_game_loop()
{
	Board* board = new Board();
	Console console = Console(board);
	GameState gameState = GameState(board);
	Player* player1 = new HumanPlayer('X', 1, board);
	Player* player2 = new HumanPlayer('O', 2, board);

	cout << "Welcome to Tic-Tac-Toe! \n";

	bool keepPlaying = true;

	while (keepPlaying) {
		start_game(board, &console, &gameState, player1, player2);

		string userResponse;

		cout << "Would you like to continue playing? Type 'no' to stop. Type anything else to continue. ";
		getline(cin, userResponse);
		
		if (userResponse == "no") {
			keepPlaying = false;
		}
		else {
			board->clear_board();
		}
	}
}

void Game::start_game(Board* board, Console* console, GameState* gameState, Player* player1, Player* player2) {
	Player* currentPlayer = player1;

	while (gameState->get_current_state() == GameState::State::InProgress) {
		cout << console->display();

		bool gotValidMove = false;
		int userMove = -1;

		while (!gotValidMove) {
			userMove = currentPlayer->get_move();

			if (!board->is_pos_in_board_bounds(userMove)) {
				cout << "Provided number (" << userMove << ") is out of board bounds. \n";
			}
			else if (board->is_pos_in_board_occupied(userMove)) {
				cout << "Tile at number: " << userMove << " is already occupied. \n";
			}
			else {
				gotValidMove = true;
			}
		}

		cout << "User move: " << userMove << endl;

		board->mark_pos(userMove, currentPlayer->get_marker());

		// Swap currentPlayer
		currentPlayer = currentPlayer == player1 ? player2 : player1;
	}

	cout << console->display();
	cout << "Good game! ";

	switch (gameState->get_current_state())
	{
	case GameState::State::Draw:
		cout << "It was a draw. \n";
		break;
	case GameState::State::Player1Win:
		cout << "Player 1 (" << player1->get_marker() << ") won!";
		break;
	case GameState::State::Player2Win:
		cout << "Player 2 (" << player2->get_marker() << ") won!";
		break;
	default:
		cout << "Unknown result.";
		break;
	}

	cout << endl;
}