#include <iostream>
#include <cassert>
#include "GameState.hpp"

using namespace std;

int main() {
	cout << "--Testing GameState." << endl;

	Board board = Board();
	GameState game_state(&board);

	// Testing a line of X
	assert(game_state.get_current_state() == GameState::State::InProgress);
	board.mark_pos(1, 'X');
	assert(game_state.get_current_state() == GameState::State::InProgress);
	board.mark_pos(2, 'X');
	assert(game_state.get_current_state() == GameState::State::InProgress);
	board.mark_pos(3, 'X');
	assert(game_state.get_current_state() == GameState::State::Player1Win);

	board.clear_board();
	assert(game_state.get_current_state() == GameState::State::InProgress);

	// Testing a line of O
	board.mark_pos(1, 'O');
	assert(game_state.get_current_state() == GameState::State::InProgress);
	board.mark_pos(2, 'O');
	assert(game_state.get_current_state() == GameState::State::InProgress);
	board.mark_pos(3, 'O');
	assert(game_state.get_current_state() == GameState::State::Player2Win);
	
	board.clear_board();
	assert(game_state.get_current_state() == GameState::State::InProgress);

	// Testing a draw
	board.mark_pos(1, 'X');
	assert(game_state.get_current_state() == GameState::State::InProgress);
	board.mark_pos(2, 'O');
	assert(game_state.get_current_state() == GameState::State::InProgress);
	board.mark_pos(3, 'X');
	assert(game_state.get_current_state() == GameState::State::InProgress);
	board.mark_pos(4, 'O');
	assert(game_state.get_current_state() == GameState::State::InProgress);
	board.mark_pos(5, 'X');
	assert(game_state.get_current_state() == GameState::State::InProgress);
	board.mark_pos(6, 'O');
	assert(game_state.get_current_state() == GameState::State::InProgress);
	board.mark_pos(7, 'O');
	assert(game_state.get_current_state() == GameState::State::InProgress);
	board.mark_pos(8, 'X');
	assert(game_state.get_current_state() == GameState::State::InProgress);
	board.mark_pos(9, 'O');
	assert(game_state.get_current_state() == GameState::State::Draw);

	cout << "--GameState tests have passed!" << endl;
}