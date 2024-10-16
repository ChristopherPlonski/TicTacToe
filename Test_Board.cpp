#include <iostream>
#include <cassert>
#include "Board.hpp"

using namespace std;

int main() {
	cout << "--Testing Board." << endl;

	Board board = Board();

	board.mark_pos(1, 'X');
	assert(board.get_mark_at_pos(1) == 'X');

	board.mark_pos(2, 'O');
	assert(board.get_mark_at_pos(2) == 'O');

	board.mark_pos(9, 'W');
	assert(board.get_mark_at_pos(9) == 'W');

	board.clear_board();
	assert(board.get_mark_at_pos(1) == NULL);

	cout << "--Board tests have passed!" << endl;
	return 0;
}