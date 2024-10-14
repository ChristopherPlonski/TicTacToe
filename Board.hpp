#ifndef BOARD_H
#define BOARD_H

class Board {

public:
	Board(int boardSize);
	void mark_pos(int boardPos, char mark);
	char get_mark_at_pos(int boardPos);
	void clear_board();
	const int GRID_SIZE;

private:
	char current_mark_grid[3][3];
	int get_row_index_from_board_pos(int position);
	int get_column_index_from_board_pos(int position);
};

#endif // !BOARD_H
