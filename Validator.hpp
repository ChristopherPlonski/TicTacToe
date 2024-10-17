#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "Board.hpp"

class Validator {

public:
	static bool is_user_move_input_valid(int userMoveInput, Board* board);

};

#endif // !VALIDATOR_H