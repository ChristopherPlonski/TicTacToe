#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>

#include "Board.hpp"
#include "Player.hpp"

using namespace std;

class GameState {

public:
	GameState(Board* board, vector<Player*>* playersVector);
	enum State {
		Player1Win,
		Player2Win,
		Draw,
		InProgress
	};
	State get_current_state();

private:
	State get_state_from_mark_array(char markArray[]);
	State get_state_from_state_array(State stateArray[]);
	State get_state_from_row(int row);
	State get_state_from_column(int column);
	State get_state_from_all_rows();
	State get_state_from_all_columns();
	State get_state_from_diagonals();
	State currentState;
	Board* board;
	vector<Player*>* playersVector;
};

#endif // !GAMESTATE_H
