#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.hpp"

class HumanPlayer : public Player {

public:
	explicit HumanPlayer(char playerMarker, int playerNumber);
	Move get_move() override;

private:

};

#endif // !HUMANPLAYER_H
