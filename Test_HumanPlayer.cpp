#include <iostream>
#include <cassert>
#include "HumanPlayer.hpp"

using namespace std;

int main() {
	cout << "--Testing HumanPlayer." << endl;

	Board board = Board();
	HumanPlayer humanPlayer = HumanPlayer('X', 1, board);

	assert(humanPlayer.get_marker() == 'X');
	assert(humanPlayer.get_number() == 1);

	humanPlayer = HumanPlayer('B', 2, board);
	assert(humanPlayer.get_marker() == 'B');
	assert(humanPlayer.get_number() == 2);

	Move inputtedMove = humanPlayer.get_move();
	cout << "Inputted move: " << inputtedMove.get_optional_mark_position().value() << endl;

	cout << "--HumanPlayer tests have passed!" << endl;
	return 0;
}