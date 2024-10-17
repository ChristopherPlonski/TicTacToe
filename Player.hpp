#ifndef PLAYER_H
#define PLAYER_H

class Player {

public:
	virtual int get_move() = 0;
	virtual char get_marker() = 0;

};

#endif // !PLAYER_H