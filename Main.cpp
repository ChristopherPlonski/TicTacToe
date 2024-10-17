#include <iostream>
#include "Board.hpp"
#include "Console.hpp"
#include "GameState.hpp"
#include "Validator.hpp"

using namespace std;

int main() {
	Board board = Board();
	Console console = Console(&board);
	GameState gameState = GameState(&board);
	Validator validator = Validator(&board);

	cout << "Welcome to Tic-Tac-Toe! \n";

	while (gameState.get_current_state() == GameState::State::InProgress) {
		cout << console.display();

		int userMove = validator.get_move();

		cout << "User move: " << userMove << endl;

		board.mark_pos(userMove, 'X');
	}

	cout << console.display();
	cout << "Good game! \n";
}