#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <optional>

#include "Move.hpp"
#include "InvalidInput.hpp"

using namespace std;

class Player {
	
public:
	Player(char playerMarker, int playerNumber);
	virtual pair<optional<Move>, optional<InvalidInput>> try_get_move_from_input(string input) = 0;
	char get_marker();
	int get_number();
	virtual string get_move_prompt_text();

private:
	char playerMarker;
	int playerNumber;

};

#endif // !PLAYER_H