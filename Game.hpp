#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Board.hpp"
#include "Console.hpp"
#include "GameState.hpp"
#include "Player.hpp"

using namespace std;

class Game {
	
public:
	void start_game_loop();

private:
	void start_game(Board* board, Console* console, GameState* gameState, vector<Player*>* playersVector);
	const int NUM_PLAYERS = 2;
};

#endif // !GAME_H