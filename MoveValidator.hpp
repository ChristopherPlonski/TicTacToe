#ifndef MOVEVALIDATOR_H
#define MOVEVALIDATOR_H

#include <utility>
#include <string>

#include "Move.hpp"
#include "Board.hpp"

using namespace std;

class MoveValidator {

public:
	static pair<bool, string> is_move_valid(Move move, Board& board);

private:
	static pair<bool, string> is_mark_move_valid(int markMove, Board& board);
};

#endif // !MOVEVALIDATOR_H
