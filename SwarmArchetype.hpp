#ifndef SWARMARCHETYPE_H
#define SWARMARCHETYPE_H

#include "ArchetypePlayer.hpp"

class SwarmArchetype : public ArchetypePlayer {

public:
	/// <summary>
	/// </summary>
	/// <param name="playerMarker"> From Player base class </param>
	/// <param name="playerNumber"> From Player base class </param>
	/// <param name="archetypeInfo"> From ArchetypePlayer base class </param>
	explicit SwarmArchetype(char playerMarker, int playerNumber, const ArchetypeInfo& archetypeInfo);

	virtual const vector<WinMarkCombination> get_win_mark_combinations_vector() const override;

	// No need to override this as the ability is passive, so the user doesn't need an extra prompt for it.
	// string get_move_prompt_text() override;

	// No need to override this as the ability is passive, so the user can't use it (and no need to change the input logic)
	//pair<optional<Move>, InvalidInput*> try_get_move_from_input(string input) override;


};

#endif // !SWARMARCHETYPE_H
