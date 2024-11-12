#ifndef PLAYER_H
#define PLAYER_H

#include "Move.hpp"

class Player {

public:
	Player(char playerMarker, int playerNumber);
	virtual Move get_move() = 0;
	char get_marker();
	int get_number();

protected:	
	void set_player_marker(char playerMarker);
	void set_player_number(int playerNumber);

private:
	char playerMarker;
	int playerNumber;

};

#endif // !PLAYER_H