#include "GameState.hpp"

#include <iostream>

using namespace std;

GameState::GameState(Board &board, vector<Player*>& playersVector)
{
	this->currentState = State::InProgress;
	this->board = &board;
	this->playersVector = &playersVector;
}

GameState::State GameState::get_current_state()
{
	State stateFromAllRows = get_state_from_all_rows();
	State stateFromAllColumns = get_state_from_all_columns();
	State stateFromAllDiagonals = get_state_from_diagonals();
	State stateFromCorners = get_state_from_corners();

	const int NUM_OF_POSSIBLE_STATES = 4;
	State allPossibleStatesArray[NUM_OF_POSSIBLE_STATES];
	allPossibleStatesArray[0] = stateFromAllRows;
	allPossibleStatesArray[1] = stateFromAllColumns;
	allPossibleStatesArray[2] = stateFromAllDiagonals;
	allPossibleStatesArray[3] = stateFromCorners;

	//for (int i = 0; i < 3; i++) {
	//	cout << "AllStates" + to_string(i) + ": " + to_string(allPossibleStatesArray[i])+", ";
	//}
	//cout << endl;

	State dominantState = get_state_from_state_array(allPossibleStatesArray, NUM_OF_POSSIBLE_STATES);

	return dominantState;
}

GameState::State GameState::get_state_from_mark_array(char markArray[], int markArraySize, Player::WinMarkCombination markArrayWinCombination)
{
	int numberOfP1Marks = 0;
	int numberOfP2Marks = 0;

	for (int i = 0; i < markArraySize; i++) {
		char markToCheck = markArray[i];

		if (markToCheck == NULL) {
			return State::InProgress;
		}

		// Will eventually have to refactor once add the ability to have >2 players.
		if (markToCheck == playersVector->at(0)->get_marker()) {
			if (player_has_mark_win_combination(playersVector->at(0)->get_win_mark_combinations_vector(), markArrayWinCombination)) {
				numberOfP1Marks++;
			}
		}
		else if (markToCheck == playersVector->at(1)->get_marker()) {
			if (player_has_mark_win_combination(playersVector->at(1)->get_win_mark_combinations_vector(), markArrayWinCombination)) {
				numberOfP2Marks++;
			}
		}
		else {
			cerr << "ERROR: Invalid markToCheck: " << markToCheck << endl;
			throw runtime_error("Invalid markToCheck.");
		}
	}

	//cout << "P1Marks: " << numberOfP1Marks << endl;
	//cout << "P2Marks: " << numberOfP2Marks << endl;
	// Could remove if-else statements since already returning, but will keep for readability sake.
	// Also, currently there will ever only be 2 players, but since Game has a vector of players, that could change, so make sure this changes too once add ability for >2 players in the future.
	if (numberOfP2Marks == markArraySize) {
		return State::Player2Win;
	}
	else if (numberOfP1Marks == markArraySize) {
		return State::Player1Win;
	}
	else {
		return State::Draw;
	}
}

GameState::State GameState::get_state_from_state_array(State stateArray[], int stateArraySize)
{
	int numberOfInProgress = 0;

	for (int i = 0; i < stateArraySize; i++) {
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
	
	return get_state_from_mark_array(markRowArray, board->BOARD_SIZE, Player::WinMarkCombination::ROWS);
}

GameState::State GameState::get_state_from_column(int column)
{
	char markColumnArray[Board::BOARD_SIZE];

	for (int i = 0; i < board->BOARD_SIZE; i++) {
		char markAtPos = board->get_mark_at_pos(i, column);

		markColumnArray[i] = markAtPos;
	}

	return get_state_from_mark_array(markColumnArray, board->BOARD_SIZE, Player::WinMarkCombination::COLUMNS);
}

GameState::State GameState::get_state_from_all_rows()
{
	State rowStatesArray[Board::BOARD_SIZE];

	for (int i = 0; i < board->BOARD_SIZE; i++) {
		State stateFromRow = get_state_from_row(i);

		rowStatesArray[i] = stateFromRow;
	}

	return get_state_from_state_array(rowStatesArray, board->BOARD_SIZE);
}

GameState::State GameState::get_state_from_all_columns()
{
	State columnStatesArray[Board::BOARD_SIZE];

	for (int i = 0; i < board->BOARD_SIZE; i++) {
		State stateFromColumn = get_state_from_column(i);

		columnStatesArray[i] = stateFromColumn;
	}

	return get_state_from_state_array(columnStatesArray, board->BOARD_SIZE);
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

	const int NUM_OF_DIAGONALS = 2;
	State diagonalsStatesArray[NUM_OF_DIAGONALS];
	diagonalsStatesArray[0] = get_state_from_mark_array(markRightSlashDiagonalArray, board->BOARD_SIZE, Player::WinMarkCombination::DIAGONALS);
	diagonalsStatesArray[1] = get_state_from_mark_array(markLeftSlashDiagonalArray, board->BOARD_SIZE, Player::WinMarkCombination::DIAGONALS);

	return get_state_from_state_array(diagonalsStatesArray, NUM_OF_DIAGONALS);
}

GameState::State GameState::get_state_from_corners()
{
	const int NUM_CORNERS = 4;
	char markCornerArray[NUM_CORNERS];

	markCornerArray[0] = board->get_mark_at_pos(0, 0);
	markCornerArray[1] = board->get_mark_at_pos(0, board->BOARD_SIZE - 1);
	markCornerArray[2] = board->get_mark_at_pos(board->BOARD_SIZE - 1, 0);
	markCornerArray[3] = board->get_mark_at_pos(board->BOARD_SIZE - 1, board->BOARD_SIZE - 1);

	return get_state_from_mark_array(markCornerArray, NUM_CORNERS, Player::WinMarkCombination::CORNERS);
}

bool GameState::player_has_mark_win_combination(vector<Player::WinMarkCombination> playerWinMarkCombinationVector, Player::WinMarkCombination winMarkCombinationToFind)
{
	for (int i = 0; i < playerWinMarkCombinationVector.size(); i++) {
		Player::WinMarkCombination winMarkCombination = playerWinMarkCombinationVector[i];

		if (winMarkCombination == winMarkCombinationToFind) {
			return true;
		}
	}

	return false;
}
