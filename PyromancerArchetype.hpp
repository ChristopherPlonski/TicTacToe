#ifndef PYROMANCERARCHETYPE_H
#define PYROMANCERARCHETYPE_H

#include "Player.hpp"

using namespace std;

class PyromancerArchetype : public Player {

public:
	explicit PyromancerArchetype(char playerMarker, int playerNumber);
	Move get_move() override;

private:

};

#endif // !PYROMANCERARCHETYPE_H
