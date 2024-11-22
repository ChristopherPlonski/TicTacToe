#include <iostream>

#include "PlayerArchetypeBuilder.hpp"
#include "PyromancerArchetype.hpp"
#include "BasicPlayer.hpp"

PlayerArchetypeBuilder::PlayerArchetypeBuilder(Board& boardReference)
{
	this->board = &boardReference;
}

Player* PlayerArchetypeBuilder::create_player_object_from_archetype_info(const ArchetypeInfo& PLAYER_ARCHETYPE_INFO_REF, char playerMarker,
	int playerNumber)
{
	ArchetypeInfo::ArchetypeType PLAYER_ARCHETYPE_TYPE = PLAYER_ARCHETYPE_INFO_REF.ARCHETYPE_TYPE;

	switch (PLAYER_ARCHETYPE_TYPE)
	{
	case ArchetypeInfo::ArchetypeType::PYROMANCER:
		return new PyromancerArchetype(playerMarker, playerNumber, PLAYER_ARCHETYPE_INFO_REF, *board);
		break;
	case ArchetypeInfo::ArchetypeType::SWARM:
		break;
	default:
		// No implementation for this archetype!
		cerr << "ERROR: No implementation for specified ArchetypeInfo::ArchetypeType value" << (int)PLAYER_ARCHETYPE_INFO_REF.ARCHETYPE_TYPE;
		throw std::runtime_error("No implementation for specified ArchetypeInfo::ArchetypeType.");
		break;
	}

	// If left out any implementation, return a BasicPlayer.
	return new BasicPlayer(playerMarker, playerNumber);
}


