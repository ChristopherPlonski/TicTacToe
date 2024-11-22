#ifndef PYROMANCERARCHETYPE_H
#define PYROMANCERARCHETYPE_H

#include "Board.hpp"
#include "ArchetypePlayer.hpp"
#include "IAbility.hpp"

using namespace std;

class PyromancerArchetype : public ArchetypePlayer, protected IAbility {

public:
	/// <summary>
	/// </summary>
	/// <param name="playerMarker"> From Player base class </param>
	/// <param name="playerNumber"> From Player base class </param>
	/// <param name="archetypeInfo"> From ArchetypePlayer base class </param>
	/// <param name="boardReference"> Allows interaction with Board for Pyromancer's ability </param>
	explicit PyromancerArchetype(char playerMarker, int playerNumber, const ArchetypeInfo& archetypeInfo, Board& boardReference);

	/// <summary>
	/// Makes the prompt text for the player's move.
	/// </summary>
	/// <returns> A string containing the complete prompt text. </returns>
	string get_move_prompt_text() override;

	/// <summary>
	/// Attempts to interpret the player's input and determine their intended move.
	/// 
	/// Handles both mark moves (placing a marker on the board) and the use of the special ability.
	/// If the input is invalid, an InvalidInput is returned.
	/// </summary>
	/// <param name="input">The player's input string.</param>
	/// <returns> A pair containing an optional Move and an optional InvalidInput. </returns>
	pair<optional<Move>, optional<InvalidInput>> try_get_move_from_input(string input) override;

protected:
	/// <summary>
	/// Attempts to use the Pyromancer's special ability based on player input.
	/// </summary>
	/// <param name="input">The player's input string.</param>
	/// <returns> A pair indicating whether the ability was used and, if not, an optional InvalidInput. </returns>
	pair<bool, optional<InvalidInput>> try_use_ability_from_input(string input) override;

	/// <summary>
	/// The ability is single-use, so it cannot be used again if it has already been activated.
	/// </summary>
	/// <returns> True if the ability can be used, false otherwise. </returns>
	bool can_use_ability() override;

	/// <summary>
	/// Pyromancer's ability is to clear the board.
	/// </summary>
	void activate_ability() override;

private:
	Board *board;
	bool usedAbility = false;
};

#endif // !PYROMANCERARCHETYPE_H
