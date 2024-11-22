#ifndef ARCHETYPEPLAYER_H
#define ARCHETYPEPLAYER_H

#include "Player.hpp"
#include "ArchetypeInfo.hpp"

class ArchetypePlayer : public Player {

public:
	explicit ArchetypePlayer(char playerMarker, int playerNumber, const ArchetypeInfo &archetypeInfo);
	
protected:
	const ArchetypeInfo& get_archetype_info() const;

private:
	const ArchetypeInfo* const ARCHETYPE_INFO;

};

#endif // !ARCHETYPEPLAYER_H