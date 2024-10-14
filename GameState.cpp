#include "GameState.hpp"

GameState::GameState(Board* board)
{
	this->currentState = GameState::State::IN_PROGRESS;
	this->board = board;
}

GameState::State GameState::get_current_state()
{
	// Need to implement
	return State::IN_PROGRESS;
}
