#ifndef PLAYER_H
#define PLAYER_H

#include "Board.hpp"

class Player {

public:
	explicit Player(char playerMarker, Board* board);
	int get_move();

private:
	Board* board;
	char playerMarker;

};

#endif // !PLAYER_H
