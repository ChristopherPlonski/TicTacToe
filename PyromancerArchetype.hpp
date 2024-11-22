#ifndef PYROMANCERARCHETYPE_H
#define PYROMANCERARCHETYPE_H

#include "Board.hpp"
#include "ArchetypePlayer.hpp"
#include "IAbility.hpp"

using namespace std;

class PyromancerArchetype : public ArchetypePlayer, protected IAbility {

public:
	explicit PyromancerArchetype(char playerMarker, int playerNumber, const ArchetypeInfo& archetypeInfo, Board& boardReference);
	Move get_move() override;
	bool can_use_ability() override;
	void activate_ability() override;

private:
	Board *board;
	bool usedAbility = false;
};

#endif // !PYROMANCERARCHETYPE_H
