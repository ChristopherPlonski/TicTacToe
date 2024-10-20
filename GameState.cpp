#include "GameState.hpp"
#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

GameState::GameState(Board* board)
{
	this->currentState = State::InProgress;
	this->board = board;
}

GameState::State GameState::get_current_state()
{
	State stateFromAllRows = get_state_from_all_rows();
	State stateFromAllColumns = get_state_from_all_columns();
	State stateFromAllDiagonals = get_state_from_diagonals();

	State allPossibleStatesArray[3];
	allPossibleStatesArray[0] = stateFromAllRows;
	allPossibleStatesArray[1] = stateFromAllColumns;
	allPossibleStatesArray[2] = stateFromAllDiagonals;

	//for (int i = 0; i < 3; i++) {
	//	cout << "AllStates" + to_string(i) + ": " + to_string(allPossibleStatesArray[i])+", ";
	//}
	//cout << endl;

	State dominantState = get_state_from_state_array(allPossibleStatesArray);

	return dominantState;
}

GameState::State GameState::get_state_from_mark_array(char markArray[])
{
	int numberOfP1Marks = 0;
	int numberOfP2Marks = 0;

	for (int i = 0; i < board->BOARD_SIZE; i++) {
		char markToCheck = markArray[i];

		if (markToCheck == NULL) {
			return State::InProgress;
		}
		else {
			if (markToCheck == 'X') {
				numberOfP1Marks++;
			}
			else if (markToCheck == 'O') {
				numberOfP2Marks++;
			}
			else {
				cout << "Invalid markToCheck: " << markToCheck << endl;
				throw("Invalid markToCheck.");
			}
		}
	}

	//cout << "P1Marks: " << numberOfP1Marks << endl;
	//cout << "P2Marks: " << numberOfP2Marks << endl;
	// Could remove if statements since already returning, but will keep for readability sake.
	// Also, currently there will ever only be 2 players, but since Game has a vector of players, that could change, so make sure this changes too.
	if (numberOfP2Marks == 0) {
		return State::Player1Win;
	}
	else if (numberOfP1Marks == 0) {
		return State::Player2Win;
	}
	else {
		return State::Draw;
	}
}

/// <summary>
/// Returns the dominant state from all the states in the given array.
/// </summary>
/// <param name="stateArray"></param>
/// <returns></returns>
GameState::State GameState::get_state_from_state_array(State stateArray[])
{
	int numberOfInProgress = 0;

	for (int i = 0; i < board->BOARD_SIZE; i++) {
		State stateTocheck = stateArray[i];

		if (stateTocheck == State::Player1Win || stateTocheck == State::Player2Win) {
			return stateTocheck;
		}
		else if (stateTocheck == State::InProgress) {
			numberOfInProgress++;
		}
	}

	if (numberOfInProgress > 0) {
		return State::InProgress;
	}

	return State::Draw;
}

GameState::State GameState::get_state_from_row(int row)
{
	char markRowArray[Board::BOARD_SIZE];

	for (int i = 0; i < board->BOARD_SIZE; i++) {
		char markAtPos = board->get_mark_at_pos(row, i);

		markRowArray[i] = markAtPos;
	}
	
	return get_state_from_mark_array(markRowArray);
}

GameState::State GameState::get_state_from_column(int column)
{
	char markColumnArray[Board::BOARD_SIZE];

	for (int i = 0; i < board->BOARD_SIZE; i++) {
		char markAtPos = board->get_mark_at_pos(i, column);

		markColumnArray[i] = markAtPos;
	}

	return get_state_from_mark_array(markColumnArray);
}

GameState::State GameState::get_state_from_all_rows()
{
	State rowStatesArray[Board::BOARD_SIZE];

	for (int i = 0; i < board->BOARD_SIZE; i++) {
		State stateFromRow = get_state_from_row(i);

		rowStatesArray[i] = stateFromRow;
	}

	return get_state_from_state_array(rowStatesArray);
}

GameState::State GameState::get_state_from_all_columns()
{
	State columnStatesArray[Board::BOARD_SIZE];

	for (int i = 0; i < board->BOARD_SIZE; i++) {
		State stateFromColumn = get_state_from_column(i);

		columnStatesArray[i] = stateFromColumn;
	}

	return get_state_from_state_array(columnStatesArray);
}

GameState::State GameState::get_state_from_diagonals()
{
	const int BOARD_SIZE = board->BOARD_SIZE;
	char markRightSlashDiagonalArray[BOARD_SIZE];

	// Would check for 3x3 board example: [0][2] [1][1] [2][0] "/"
	for (int i = 0; i < BOARD_SIZE; i++) {
		char markAtPos = board->get_mark_at_pos(i, BOARD_SIZE - i - 1);

		markRightSlashDiagonalArray[i] = markAtPos;
	}

	char markLeftSlashDiagonalArray[BOARD_SIZE];

	// Would check for 3x3 board example: [0][0] [1][1] [2][2] "\"
	for (int i = 0; i < BOARD_SIZE; i++) {
		char markAtPos = board->get_mark_at_pos(i, i);

		markLeftSlashDiagonalArray[i] = markAtPos;
	}

	State diagonalsStatesArray[2];
	diagonalsStatesArray[0] = get_state_from_mark_array(markRightSlashDiagonalArray);
	diagonalsStatesArray[1] = get_state_from_mark_array(markLeftSlashDiagonalArray);

	return get_state_from_state_array(diagonalsStatesArray);
}
