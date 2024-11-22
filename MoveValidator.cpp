#include "MoveValidator.hpp"

MoveValidator::MoveValidationType MoveValidator::is_move_valid(Move move, Board &board)
{
	bool playerDidMarkMove = move.get_optional_mark_position().has_value();

	if (!move.used_turn_ending_ability() && !playerDidMarkMove) {
		throw runtime_error("User move didn't mark position or use ability!\n");
		return MoveValidationType::MOVE_ERROR;
	}
	
	if (playerDidMarkMove) {
		int userMoveNumber = move.get_optional_mark_position().value();

		MoveValidationType isMarkMoveValidType = is_mark_move_valid(userMoveNumber, board);

		if (isMarkMoveValidType != MoveValidationType::VALID_MOVE) {
			return isMarkMoveValidType;
		}
	}

    return MoveValidationType::VALID_MOVE;
}

MoveValidator::MoveValidationType MoveValidator::is_mark_move_valid(int markMove, Board &board)
{
	if (!board.is_pos_in_board_bounds(markMove)) {
		return MoveValidationType::OUT_OF_BOARD_BOUNDS;
	}

	if (board.is_pos_in_board_occupied(markMove)) {
		return MoveValidationType::MARK_MOVE_SPACE_OCCUPIED;
	}

	return MoveValidationType::VALID_MOVE;
}
