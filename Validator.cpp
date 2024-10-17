#include <iostream>

#include "Validator.hpp"

using namespace std;

bool Validator::is_user_move_input_valid(int userMoveInput, Board* board)
{
	if (!board->is_pos_in_board_bounds(userMoveInput)) {
		cout << "Provided number (" << userMoveInput << ") is out of board bounds. \n";
		return false;
	}
	
	if (board->get_mark_at_pos(userMoveInput) != NULL) {
		cout << "Tile at number: " << userMoveInput << " is already occupied. \n";
		return false;
	}

	// Got a valid input!
	return true;
}
