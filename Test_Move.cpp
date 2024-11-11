#include <cassert>
#include <iostream>

#include "Move.hpp"

using namespace std;

int main() {
	cout << "--Testing Move \n";

	Move boardMove = Move(5);
	assert(boardMove.get_optional_mark_position().value() == 5);
	assert(boardMove.used_ability() == false);
	
	boardMove = Move(-100);
	assert(boardMove.get_optional_mark_position().value() == -100);
	assert(boardMove.used_ability() == false);

	boardMove = Move(234);
	assert(boardMove.get_optional_mark_position().value() == 234);
	assert(boardMove.used_ability() == false);

	boardMove = Move(0);
	assert(boardMove.get_optional_mark_position().value() == 0);
	assert(boardMove.used_ability() == false);

	Move abilityMove = Move();
	assert(abilityMove.get_optional_mark_position().has_value() == false);
	assert(abilityMove.used_ability() == true);

	cout << "--Move tests have passed! \n";
}