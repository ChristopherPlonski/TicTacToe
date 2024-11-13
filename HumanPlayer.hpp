#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.hpp"
#include "Board.hpp"

class HumanPlayer : public Player {

public:
	explicit HumanPlayer(char playerMarker, int playerNumber);
	Move get_move() override;
	static char prompt_new_marker(int playerNumber);
	char prompt_new_marker();

private:

};

#endif // !HUMANPLAYER_H
