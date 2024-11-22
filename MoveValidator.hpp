#ifndef MOVEVALIDATOR_H
#define MOVEVALIDATOR_H

#include "Move.hpp"
#include "Board.hpp"

using namespace std;

class MoveValidator {

public:
	enum class MoveValidationType {
		VALID_MOVE,
		OUT_OF_BOARD_BOUNDS,
		MARK_MOVE_SPACE_OCCUPIED,
		MOVE_ERROR
	};

	/// <summary>
	/// Returns a MoveValidator::MoveValidationType which represents whether or not the move was valid.
	/// </summary>
	static MoveValidator::MoveValidationType is_move_valid(Move move, Board& board);

private:
	/// <summary>
	/// Returns a MoveValidator::MoveValidationType which represents whether or not the mark move was valid.
	/// </summary>
	static MoveValidator::MoveValidationType is_mark_move_valid(int markMove, Board& board);
};

#endif // !MOVEVALIDATOR_H
