#ifndef PLAYERARCHETYPEBUILDER_H
#define PLAYERARCHETYPEBUILDER_H

#include "Board.hpp"
#include "Player.hpp"
#include "ArchetypeInfo.hpp"

class PlayerArchetypeBuilder {

public:
	PlayerArchetypeBuilder(Board &boardReference);
	Player* create_player_object_from_archetype_type(ArchetypeInfo::ArchetypeType playerArchetypeType, char playerMarker, int playerNumber);

private:
	Board* board;

};

#endif // !PLAYERARCHETYPEBUILDER_H
