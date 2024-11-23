#include "SwarmArchetype.hpp"

SwarmArchetype::SwarmArchetype(char playerMarker, int playerNumber, const ArchetypeInfo& archetypeInfo) : ArchetypePlayer(playerMarker, playerNumber, archetypeInfo)
{

}

const vector<Player::WinMarkCombination> SwarmArchetype::get_win_mark_combinations_vector() const
{
	return vector<WinMarkCombination> {
		WinMarkCombination::ROWS,
		WinMarkCombination::COLUMNS,
		WinMarkCombination::DIAGONALS,
		WinMarkCombination::CORNERS

	};
}