#include <iostream>
#include <cassert>
#include <vector>

#include "GameState.hpp"
#include "BasicPlayer.hpp"
#include "SwarmArchetype.hpp"

using namespace std;

int main() {
	cout << "--Testing GameState." << endl;

	Board board = Board();
	vector<Player*> playerList = vector<Player*>();
	playerList.push_back(new SwarmArchetype('X', 1, ArchetypeInfo(ArchetypeInfo::ArchetypeType::SWARM, " ", " ", " ")));
	playerList.push_back(new BasicPlayer('O', 2));

	GameState gameState(board, playerList);

	// Testing a row of X
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(1, 'X');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(2, 'X');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(3, 'X');
	assert(gameState.get_current_state() == GameState::State::Player1Win);

	board.clear_board();
	assert(gameState.get_current_state() == GameState::State::InProgress);

	// Testing a row of O
	board.mark_pos(1, 'O');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(2, 'O');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(3, 'O');
	assert(gameState.get_current_state() == GameState::State::Player2Win);
	
	board.clear_board();
	assert(gameState.get_current_state() == GameState::State::InProgress);

	// Testing a column of X
	board.mark_pos(1, 'X');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(4, 'X');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(7, 'X');
	assert(gameState.get_current_state() == GameState::State::Player1Win);

	board.clear_board();
	assert(gameState.get_current_state() == GameState::State::InProgress);

	// Testing a column of O
	board.mark_pos(1, 'O');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(4, 'O');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(7, 'O');
	assert(gameState.get_current_state() == GameState::State::Player2Win);

	board.clear_board();
	assert(gameState.get_current_state() == GameState::State::InProgress);

	// Testing both diagonals
	board.mark_pos(1, 'X');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(5, 'X');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(9, 'X');
	assert(gameState.get_current_state() == GameState::State::Player1Win);

	board.clear_board();
	assert(gameState.get_current_state() == GameState::State::InProgress);

	board.mark_pos(3, 'X');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(5, 'X');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(7, 'X');
	assert(gameState.get_current_state() == GameState::State::Player1Win);

	board.clear_board();
	assert(gameState.get_current_state() == GameState::State::InProgress);

	// Testing corners with a player that can't win with corners.
	board.mark_pos(1, 'O');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(3, 'O');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(7, 'O');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(9, 'O');
	assert(gameState.get_current_state() == GameState::State::InProgress);

	board.clear_board();
	assert(gameState.get_current_state() == GameState::State::InProgress);

	// Testing corners with a player that can win with corners.
	board.mark_pos(1, 'X');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(3, 'X');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(7, 'X');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(9, 'X');
	assert(gameState.get_current_state() == GameState::State::Player1Win);

	board.clear_board();
	assert(gameState.get_current_state() == GameState::State::InProgress);

	// Testing a draw
	board.mark_pos(1, 'X');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(2, 'O');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(3, 'X');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(4, 'O');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(5, 'X');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(6, 'O');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(7, 'O');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(8, 'X');
	assert(gameState.get_current_state() == GameState::State::InProgress);
	board.mark_pos(9, 'O');
	assert(gameState.get_current_state() == GameState::State::Draw);

	board.clear_board();
	assert(gameState.get_current_state() == GameState::State::InProgress);

	cout << "--GameState tests have passed!" << endl;
}