#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>

#include "Board.hpp"
#include "Player.hpp"

using namespace std;

class GameState {

public:
	GameState(Board &board, vector<Player*>& playersVector);
	enum class State {
		Player1Win,
		Player2Win,
		Draw,
		InProgress
	};
	State get_current_state();

private:
	State get_state_from_mark_array(char markArray[], int markArraySize, int markCountToCountAsWin);

	/// <summary>
	/// Analyzes the states in the givenStateArray and returns the dominant state.
	/// </summary>
	/// <param name="stateArray"></param>
	/// <param name="stateArraySize"></param>
	/// <returns> The dominant state of the game </returns>
	State get_state_from_state_array(State stateArray[], int stateArraySize);
	State get_state_from_row(int row);
	State get_state_from_column(int column);
	State get_state_from_all_rows();
	State get_state_from_all_columns();
	State get_state_from_diagonals();
	State get_state_from_corners();
	State currentState;
	Board* board;
	vector<Player*>* playersVector;
};

#endif // !GAMESTATE_H
