#include "ArchetypePlayer.hpp"

ArchetypePlayer::ArchetypePlayer(char playerMarker, int playerNumber, const ArchetypeInfo &archetypeInfo): ARCHETYPE_INFO(&archetypeInfo), BasicPlayer(playerMarker, playerNumber)
{

}

const ArchetypeInfo& ArchetypePlayer::get_archetype_info() const
{
	//return ArchetypeInfo(ArchetypeInfo::ArchetypeType::PYROMANCER, "", "", "");
	return *ARCHETYPE_INFO;
}
