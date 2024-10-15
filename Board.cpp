#include "Board.hpp"
#include <iostream>
#include <stdexcept> // For std::out_of_range

using namespace std;

Board::Board(int boardSize) : BOARD_SIZE(boardSize) {
	this->current_mark_grid = new char*[boardSize];

	for (int i = 0; i < boardSize; i++) {
		current_mark_grid[i] = new char[boardSize];
	}
}

Board::~Board()
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		delete[] current_mark_grid[i];
	}

	delete[] current_mark_grid;
}

int Board::get_row_index_from_board_pos(int boardPos) {
	int index = boardPos - 1;
	return index / BOARD_SIZE;
}

int Board::get_column_index_from_board_pos(int boardPos) {
	int index = boardPos - 1;
	return index % BOARD_SIZE;
}


void Board::mark_pos(int boardPos, char mark)
{
	if (boardPos < 1 || boardPos > BOARD_SIZE * BOARD_SIZE) {
		cout << "Index is out of bounds!";
		throw out_of_range("Index is out of bounds.");
		return;
	}

	int row = get_row_index_from_board_pos(boardPos);
	int column = get_column_index_from_board_pos(boardPos);

	this->current_mark_grid[row][column] = mark;
}

char Board::get_mark_at_pos(int boardPos)
{
	if (boardPos < 1 || boardPos > BOARD_SIZE * BOARD_SIZE) {
		cout << "Index is out of bounds!";
		throw out_of_range("Index is out of bounds.");
		return NULL;
	}


	int row = get_row_index_from_board_pos(boardPos);
	int column = get_column_index_from_board_pos(boardPos);

	return this->current_mark_grid[row][column];
}

void Board::clear_board()
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			current_mark_grid[i][j] = NULL;
		}
	}
}
