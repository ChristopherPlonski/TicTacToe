#include <iostream>
#include <cassert>

#include "BasicPlayer.hpp"
#include "Board.hpp"

using namespace std;

int main() {
	cout << "--Testing BasicPlayer." << endl;

	Board board = Board();
	BasicPlayer humanPlayer = BasicPlayer('X', 1);

	assert(humanPlayer.get_marker() == 'X');
	assert(humanPlayer.get_number() == 1);

	humanPlayer = BasicPlayer('B', 2);
	assert(humanPlayer.get_marker() == 'B');
	assert(humanPlayer.get_number() == 2);

	assert(humanPlayer.try_get_move_from_input("1").first.value().get_optional_mark_position().value() == 1);
	assert(humanPlayer.try_get_move_from_input("1").second == nullptr);

	assert(humanPlayer.try_get_move_from_input("100").first.value().get_optional_mark_position().value() == 100);
	assert(humanPlayer.try_get_move_from_input("100").second == nullptr);

	assert(humanPlayer.try_get_move_from_input(" hello world! ").first.has_value() == false);
	assert(humanPlayer.try_get_move_from_input(" hello world! ").second != nullptr);

	cout << "--BasicPlayer tests have passed!" << endl;
	return 0;
}