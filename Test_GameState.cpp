#include <iostream>
#include <cassert>
#include "GameState.hpp"

using namespace std;

int main() {
	cout << "--Testing GameState." << endl;

	Board board = Board(3);
	GameState game_state(&board);

	assert(game_state.get_current_state() == GameState::State::IN_PROGRESS);

	board.mark_pos(1, 'X');
	board.mark_pos(2, 'X');
	board.mark_pos(3, 'X');
	assert(game_state.get_current_state() == GameState::State::IN_PROGRESS);

	cout << "--GameState tests have passed!" << endl;
}