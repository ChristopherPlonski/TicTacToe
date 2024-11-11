#include <iostream>

#include "Game.hpp"
#include "HumanPlayer.hpp"
#include "Settings.hpp"
#include "StringConverter.hpp"

using namespace std;

void Game::start_game_loop()
{
	Board* board = new Board();
	Console console = Console(board);
	Settings settings = Settings();

	cout << "Welcome to Tic-Tac-Toe! \n";

	vector<Player*>* playersVector = new vector<Player*>();

	for (int i = 0; i < NUM_PLAYERS; i++) {
		int playerNumber = i + 1;
		char playerMarker = settings.get_valid_marker_for_human_player(playerNumber, playersVector);

		HumanPlayer* newPlayer = new HumanPlayer(playerMarker, playerNumber, board);
		playersVector->push_back(newPlayer);
	}

	GameState gameState = GameState(board, playersVector);

	bool keepPlaying = true;

	while (keepPlaying) {
		start_game(board, &console, &gameState, playersVector);

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

void Game::start_game(Board* board, Console* console, GameState* gameState, vector<Player*>* playersVector) {
	int currentPlayerIndex = 0;

	while (gameState->get_current_state() == GameState::State::InProgress) {
		Player* currentPlayer = playersVector->at(currentPlayerIndex);

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

		// Set currentPlayer to next player
		if (currentPlayerIndex == playersVector->size() - 1) {
			currentPlayerIndex = 0;
		}
		else {
			currentPlayerIndex++;
		}
	}

	cout << console->display();
	cout << "Good game! ";

	switch (gameState->get_current_state())
	{
	case GameState::State::Draw:
		cout << "It was a draw. \n";
		break;
	case GameState::State::Player1Win:
		cout << "Player 1 (" << playersVector->at(0)->get_marker() << ") won!";
		break;
	case GameState::State::Player2Win:
		cout << "Player 2 (" << playersVector->at(1)->get_marker() << ") won!";
		break;
	default:
		cout << "Unknown result.";
		break;
	}

	cout << endl;
}