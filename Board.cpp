#include "Board.hpp"
#include <iostream>
#include <stdexcept> // For std::out_of_range

using namespace std;

Board::Board() {
	this->current_mark_grid = new char*[BOARD_SIZE];

	for (int i = 0; i < BOARD_SIZE; i++) {
		current_mark_grid[i] = new char[BOARD_SIZE];
	}

	clear_board();
}

Board::~Board()
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		delete[] current_mark_grid[i];
	}

	delete[] current_mark_grid;
}

int Board::get_row_index_from_board_pos(int boardPos) const {
	int index = boardPos - 1;
	return index / BOARD_SIZE;
}

int Board::get_column_index_from_board_pos(int boardPos) const {
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

char Board::get_mark_at_pos(int rowIndex, int columnIndex)
{
	if (rowIndex < 0 || rowIndex > BOARD_SIZE - 1 || columnIndex < 0 || columnIndex > BOARD_SIZE - 1) {
		cout << "Index is out of bounds!";
		throw out_of_range("Index is out of bounds.");
		return NULL;
	}

	return this->current_mark_grid[rowIndex][columnIndex];
}

void Board::clear_board()
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			current_mark_grid[i][j] = NULL;
		}
	}
}
