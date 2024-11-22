#ifndef PLAYERARCHETYPEBUILDER_H
#define PLAYERARCHETYPEBUILDER_H

#include "Board.hpp"
#include "Player.hpp"
#include "ArchetypeInfo.hpp"

class PlayerArchetypeBuilder {

public:
	PlayerArchetypeBuilder(Board &boardReference);
	Player* create_player_object_from_archetype_info(const ArchetypeInfo& PLAYER_ARCHETYPE_INFO_REF, char playerMarker, int playerNumber);

private:
	Board* board;

};

#endif // !PLAYERARCHETYPEBUILDER_H
