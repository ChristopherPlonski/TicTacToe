#ifndef PLAYER_H
#define PLAYER_H

#include "Board.hpp"

class Player {

public:
	explicit Player(char playerMarker, int playerNumber, Board* board);
	int get_move();
	char get_marker();

private:
	Board* board;
	char playerMarker;
	int playerNumber;
};

#endif // !PLAYER_H
