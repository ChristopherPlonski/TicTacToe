#include "ArchetypePlayer.hpp"

ArchetypePlayer::ArchetypePlayer(char playerMarker, int playerNumber, const ArchetypeInfo &archetypeInfo) : Player(playerMarker, playerNumber), ARCHETYPE_INFO(&archetypeInfo)
{

}

const ArchetypeInfo& ArchetypePlayer::get_archetype_info() const
{
	return *ARCHETYPE_INFO;
}
