#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.hpp"
#include "Board.hpp"

class HumanPlayer : public Player {

public:
	explicit HumanPlayer(char playerMarker, int playerNumber, Board &board);
	Move get_move() override;
	char get_marker() override;
	static char prompt_new_marker(int playerNumber);
	char prompt_new_marker();
	int get_number();

private:
	Board* board;
	char playerMarker;
	int playerNumber;

};

#endif // !HUMANPLAYER_H
