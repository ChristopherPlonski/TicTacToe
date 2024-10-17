#ifndef GAME_H
#define GAME_H

#include "Board.hpp"
#include "Console.hpp"
#include "GameState.hpp"
#include "Player.hpp"

class Game {
	
public:
	void start_game_loop();

private:
	void start_game(Board* board, Console* console, GameState* gameState, Player* player1, Player* player2);

};

#endif // !GAME_H