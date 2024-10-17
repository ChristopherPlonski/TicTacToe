#include <iostream>

#include "Game.hpp"
#include "Board.hpp"
#include "Console.hpp"
#include "GameState.hpp"
#include "Validator.hpp"
#include "Player.hpp"

using namespace std;

void Game::start_game_loop()
{
	Board board = Board();
	Console console = Console(&board);
	GameState gameState = GameState(&board);
	Player player1 = Player('X', &board);
	Player player2 = Player('O', &board);

	cout << "Welcome to Tic-Tac-Toe! \n";

	while (gameState.get_current_state() == GameState::State::InProgress) {
		cout << console.display();

		int userMove = player1.get_move();

		cout << "User move: " << userMove << endl;

		board.mark_pos(userMove, 'X');
	}

	cout << console.display();
	cout << "Good game! ";

	switch (gameState.get_current_state())
	{
	case GameState::State::Draw:
		cout << "It was a draw. \n";
		break;
	case GameState::State::Player1Win:
		cout << "Player 1 won!";
		break;
	case GameState::State::Player2Win:
		cout << "Player 2 won!";
		break;
	default:
		cout << "Unknown result.";
		break;
	}
}