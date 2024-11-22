#include "SwarmArchetype.hpp"

SwarmArchetype::SwarmArchetype(char playerMarker, int playerNumber, const ArchetypeInfo& archetypeInfo) : ArchetypePlayer(playerMarker, playerNumber, archetypeInfo)
{

}

const Player::WinMarkCombination* SwarmArchetype::get_win_mark_combinations_array() const
{
	return new WinMarkCombination[4]{
		WinMarkCombination::ROWS,
		WinMarkCombination::COLUMNS,
		WinMarkCombination::DIAGONALS,
		WinMarkCombination::CORNERS
	};
}