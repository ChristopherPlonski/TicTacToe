#ifndef ARCHETYPEINFO_H
#define ARCHETYPEINFO_H

#include <string>

using namespace std;

struct ArchetypeInfo {

public:
	enum class ArchetypeType {
		PYROMANCER,
		SWARM
	};

	ArchetypeInfo(ArchetypeType archetypeType, string archetypeName, string archetypeDescription, string archetypeAbilityDescription);
	const ArchetypeType ARCHETYPE_TYPE;
	const string ARCHETYPE_NAME;
	const string ARCHETYPE_DESCRIPTION;
	const string ARCHETYPE_ABILITY_DESCRIPTION;
};

#endif // !ARCHETYPEINFO_H