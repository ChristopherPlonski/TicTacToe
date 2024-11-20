#include "ArchetypeInfoHandler.hpp"

ArchetypeInfoHandler::ArchetypeInfoHandler() : ARCHETYPE_INFOS_ARRAY{
	ArchetypeInfo(ArchetypeInfo::ArchetypeType::PYROMANCER, "Pyromancer", "Burn the whole board alive!", "Clear the whole board. Uses up your turn."),
	ArchetypeInfo(ArchetypeInfo::ArchetypeType::SWARM, "Swarm", "Use the corners to your advantage!", "Non-useable. Gain the ability to win with the 4 corners.")
}
{

}

// TODO: THIS
ArchetypeInfo::ArchetypeType ArchetypeInfoHandler::get_user_to_pick_archetype_type()
{
	return ArchetypeInfo::ArchetypeType::PYROMANCER;
}
