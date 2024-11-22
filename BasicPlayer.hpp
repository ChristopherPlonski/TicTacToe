#ifndef BASICPLAYER_H
#define BASICPLAYER_H

#include "Player.hpp"

class BasicPlayer : public Player {

public:
	explicit BasicPlayer(char playerMarker, int playerNumber);

	/// <summary>
	/// Makes the prompt text for the player's move.
	/// </summary>
	/// <returns> A string containing the complete prompt text. </returns>
	string get_move_prompt_text() override;

	/// <summary>
	/// Attempts to interpret the player's input and determine their intended move.
	/// 
	/// Handles mark moves (placing a marker on the board).
	/// If the input is invalid, an InvalidInput is returned.
	/// </summary>
	/// <param name="input">The player's input string.</param>
	/// <returns> A pair containing an optional Move and an optional InvalidInput. </returns>
	pair<optional<Move>, InvalidInput*> try_get_move_from_input(string input) override;
};

#endif // !BASICPLAYER_H
