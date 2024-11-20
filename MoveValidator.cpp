#include "MoveValidator.hpp"

pair<bool, string> MoveValidator::is_move_valid(Move move, Board &board)
{
	bool playerDidMarkMove = move.get_optional_mark_position().has_value();

	if (!move.used_turn_ending_ability() && !playerDidMarkMove) {
		string resultMessage = "ERROR: User move didn't mark position or use ability!\n";
		return pair<bool, string>(false, resultMessage);
	}
	
	if (playerDidMarkMove) {
		int userMoveNumber = move.get_optional_mark_position().value();

		pair<bool, string> isMarkMoveValidResult = is_mark_move_valid(userMoveNumber, board);
		if (!isMarkMoveValidResult.first) {
			return pair<bool, string>(false, isMarkMoveValidResult.second);
		}
	}

    return pair<bool, string>(true, "");
}

/// <summary>
/// Returns a pair<bool, string>. Bool represents whether or not the move was valid, the string represents the result message (if any)
/// </summary>
pair<bool, string> MoveValidator::is_mark_move_valid(int markMove, Board &board)
{
	if (!board.is_pos_in_board_bounds(markMove)) {
		string resultMessage = "Provided number (" + to_string(markMove) + ") is out of board bounds.\n";
		return pair<bool, string>(false, resultMessage);
	}

	if (board.is_pos_in_board_occupied(markMove)) {
		string resultMessage = "Tile at number: " + to_string(markMove) + " is already occupied. \n";
		return pair<bool, string>(false, resultMessage);
	}

	return pair<bool, string>(true, "");
}
