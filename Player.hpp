#ifndef PLAYER_H
#define PLAYER_H

#include "Move.hpp"

class Player {

public:
	virtual Move get_move() = 0;
	virtual char get_marker() = 0;

};

#endif // !PLAYER_H