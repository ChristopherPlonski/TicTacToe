#include <iostream>
#include <cassert>

#include "BasicPlayer.hpp"
#include "Board.hpp"

using namespace std;

int main() {
	cout << "--Testing BasicPlayer." << endl;

	Board board = Board();
	BasicPlayer humanPlayer = BasicPlayer('X', 1);

	assert(humanPlayer.get_marker() == 'X');
	assert(humanPlayer.get_number() == 1);

	humanPlayer = BasicPlayer('B', 2);
	assert(humanPlayer.get_marker() == 'B');
	assert(humanPlayer.get_number() == 2);

	Move inputtedMove = humanPlayer.get_move();
	cout << "Inputted move: " << inputtedMove << endl;

	cout << "--BasicPlayer tests have passed!" << endl;
	return 0;
}