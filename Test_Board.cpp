#include <iostream>
#include <cassert>
#include "Board.hpp"

using namespace std;

int main() {
	cout << "--Testing Board." << endl;

	Board board = Board();

	assert(board.is_pos_in_board_occupied(1) == false);
	board.mark_pos(1, 'X');
	assert(board.get_mark_at_pos(1) == 'X');
	assert(board.is_pos_in_board_occupied(1) == true);

	assert(board.is_pos_in_board_occupied(2) == false);
	board.mark_pos(2, 'O');
	assert(board.get_mark_at_pos(2) == 'O');
	assert(board.is_pos_in_board_occupied(2) == true);

	assert(board.is_pos_in_board_occupied(9) == false);
	board.mark_pos(9, 'W');
	assert(board.get_mark_at_pos(9) == 'W');
	assert(board.is_pos_in_board_occupied(9) == true);

	board.clear_board();
	assert(board.get_mark_at_pos(1) == NULL);

	assert(board.is_pos_in_board_bounds(0) == false);
	assert(board.is_pos_in_board_bounds(10) == false);
	assert(board.is_pos_in_board_bounds(100) == false);
	assert(board.is_pos_in_board_bounds(-100) == false);
	assert(board.is_pos_in_board_bounds(1) == true);
	assert(board.is_pos_in_board_bounds(9) == true);
	assert(board.is_pos_in_board_bounds(5) == true);

	cout << "--Board tests have passed!" << endl;
	return 0;
}