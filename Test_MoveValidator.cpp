#include <cassert>
#include <iostream>
#include <utility>
#include <string>

#include "MoveValidator.hpp"
#include "Move.hpp"
#include "Board.hpp"

using namespace std;

int main() {
	cout << "--Testing MoveValidator \n";

	Board board = Board();

	Move boardMove = Move(5);
	assert(MoveValidator::is_move_valid(boardMove, board) == MoveValidator::MoveValidationType::VALID_MOVE);
	board.mark_pos(5, 'X');
	assert(MoveValidator::is_move_valid(boardMove, board) == MoveValidator::MoveValidationType::MARK_MOVE_SPACE_OCCUPIED);

	assert(MoveValidator::is_move_valid(Move(10), board) == MoveValidator::MoveValidationType::OUT_OF_BOARD_BOUNDS);
	assert(MoveValidator::is_move_valid(Move(0), board) == MoveValidator::MoveValidationType::OUT_OF_BOARD_BOUNDS);
	assert(MoveValidator::is_move_valid(Move(-100), board) == MoveValidator::MoveValidationType::OUT_OF_BOARD_BOUNDS);
	assert(MoveValidator::is_move_valid(Move(234), board) == MoveValidator::MoveValidationType::OUT_OF_BOARD_BOUNDS);
	assert(MoveValidator::is_move_valid(Move(1), board) == MoveValidator::MoveValidationType::VALID_MOVE);
	assert(MoveValidator::is_move_valid(Move(9), board) == MoveValidator::MoveValidationType::VALID_MOVE);

	Move abilityMove = Move();
	assert(MoveValidator::is_move_valid(abilityMove, board) == MoveValidator::MoveValidationType::VALID_MOVE);


	cout << "--MoveValidator tests have passed! \n";
}