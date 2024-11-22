#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <optional>

#include "Move.hpp"
#include "InvalidInput.hpp"

using namespace std;

// Design note: I could turn this into an 'inteface' instead of the base class for players. Yes, all players should technically have a marker and number attribute, but
// putting those methods in the interface contract will basically force that either way. This could decrease the coupling that I have currently with subclasses of this.
class Player {
	
public:
	Player(char playerMarker, int playerNumber);
	virtual pair<optional<Move>, InvalidInput*> try_get_move_from_input(string input) = 0;
	char get_marker();
	int get_number();
	virtual string get_move_prompt_text();

private:
	char playerMarker;
	int playerNumber;

};

#endif // !PLAYER_H