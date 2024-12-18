#ifndef ARCHETYPEINFOHANDLER_H
#define ARCHETYPEINFOHANDLER_H

#include <array>

#include "ArchetypeInfo.hpp"

using namespace std;

class ArchetypeInfoHandler {

public:
	static const int NUMBER_OF_ARCHETYPES = 2;

	ArchetypeInfoHandler();
	ArchetypeInfo get_user_to_pick_archetype();
	ArchetypeInfo get_archetype_info_from_archetype_type(ArchetypeInfo::ArchetypeType archetypeType);

private:
	const array<ArchetypeInfo, NUMBER_OF_ARCHETYPES> ARCHETYPE_INFOS_ARRAY;
};

#endif // !ARCHETYPEINFOHANDLER_H
