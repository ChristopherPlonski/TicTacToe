#ifndef BOARD_H
#define BOARD_H

class Board {

public:
	Board();
	~Board();
	void mark_pos(int boardPos, char mark);
	char get_mark_at_pos(int boardPos);
	char get_mark_at_pos(int rowIndex, int columnIndex);
	bool is_pos_in_board_bounds(int boardPos);
	bool is_pos_in_board_bounds(int rowIndex, int columnIndex);
	bool is_pos_in_board_occupied(int boardPos);
	bool is_pos_in_board_occupied(int rowIndex, int columnIndex);
	void clear_board();
	static const int BOARD_SIZE = 3;

private:
	char** current_mark_grid;
	int get_row_index_from_board_pos(int position) const;
	int get_column_index_from_board_pos(int position) const;
};

#endif // !BOARD_H
