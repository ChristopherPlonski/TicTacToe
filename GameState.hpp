#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Board.hpp"

class GameState {

public:
	GameState(Board* board);
	enum State {
		WIN,
		LOSE,
		DRAW,
		IN_PROGRESS
	};
	State get_current_state();

private:

	State currentState;
	Board* board;
};

#endif // !GAMESTATE_H
