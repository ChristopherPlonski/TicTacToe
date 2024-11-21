#include <iostream>

#include "PlayerArchetypeBuilder.hpp"
#include "PyromancerArchetype.hpp"
#include "BasicPlayer.hpp"

PlayerArchetypeBuilder::PlayerArchetypeBuilder(Board& boardReference)
{
	this->board = &boardReference;
}

Player* PlayerArchetypeBuilder::create_player_object_from_archetype_type(ArchetypeInfo::ArchetypeType playerArchetypeType, char playerMarker,
	int playerNumber)
{
	if (playerArchetypeType == ArchetypeInfo::ArchetypeType::PYROMANCER) {
		return new PyromancerArchetype(playerMarker, playerNumber);
	}
	else {
		// No implementation for this archetype!
		cerr << "ERROR: No implementation for specified ArchetypeInfo::ArchetypeType value" << (int)playerArchetypeType;
		throw std::runtime_error("No implementation for specified ArchetypeInfo::ArchetypeType.");
	}

	// If left out any implementation, return a BasicPlayer.
	return new BasicPlayer(playerMarker, playerNumber);
}


