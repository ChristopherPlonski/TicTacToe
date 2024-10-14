#include "Board.hpp"
#include <stdexcept> // For std::out_of_range

using namespace std;

Board::Board(int boardSize) : GRID_SIZE(boardSize) {

}

int Board::get_row_index_from_board_pos(int boardPos) {
	int index = boardPos - 1;
	return index / GRID_SIZE;
}

int Board::get_column_index_from_board_pos(int boardPos) {
	int index = boardPos - 1;
	return index % GRID_SIZE;
}


void Board::mark_pos(int boardPos, char mark)
{
	if (boardPos < 1 || boardPos > 9) {
		throw out_of_range("Index is out of bounds.");
		return;
	}

	int row = get_row_index_from_board_pos(boardPos);
	int column = get_column_index_from_board_pos(boardPos);

	this->current_mark_grid[row][column] = mark;
}

char Board::get_mark_at_pos(int boardPos)
{
	int row = get_row_index_from_board_pos(boardPos);
	int column = get_column_index_from_board_pos(boardPos);

	return this->current_mark_grid[row][column];
}

void Board::clear_board()
{
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			current_mark_grid[i][j] = NULL;
		}
	}
}
