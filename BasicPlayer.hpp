#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.hpp"

class BasicPlayer : public Player {

public:
	explicit BasicPlayer(char playerMarker, int playerNumber);
	Move get_move() override;

private:

};

#endif // !HUMANPLAYER_H
