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
	assert(MoveValidator::is_move_valid(boardMove, board).first == true);
	board.mark_pos(5, 'X');
	assert(MoveValidator::is_move_valid(boardMove, board).first == false);

	assert(MoveValidator::is_move_valid(Move(10), board).first == false);
	assert(MoveValidator::is_move_valid(Move(0), board).first == false);
	assert(MoveValidator::is_move_valid(Move(-100), board).first == false);
	assert(MoveValidator::is_move_valid(Move(234), board).first == false);
	assert(MoveValidator::is_move_valid(Move(1), board).first == true);
	assert(MoveValidator::is_move_valid(Move(9), board).first == true);

	Move abilityMove = Move();
	assert(MoveValidator::is_move_valid(abilityMove, board).first == true);


	cout << "--MoveValidator tests have passed! \n";
}