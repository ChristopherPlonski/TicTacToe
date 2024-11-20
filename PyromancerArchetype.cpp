#include <iostream>
#include <string>

#include "PyromancerArchetype.hpp"
#include "StringConverter.hpp"

PyromancerArchetype::PyromancerArchetype(char playerMarker, int playerNumber) : Player(playerMarker, playerNumber)
{
	
}

Move PyromancerArchetype::get_move()
{
	bool gotValidIntMove = false;
	int userValidMove;

	while (!gotValidIntMove) {
		cout << "Player #" << Player::get_number() << " (" << Player::get_marker() << "), what do you want your move to be?";

		string userStringInput;
		getline(cin, userStringInput);

		optional<int> optionalUserIntInput = StringConverter::try_get_int_from_string(userStringInput);

		if (!optionalUserIntInput.has_value()) {
			cout << "Provided input was not a valid number. \n";
		}
		else {
			gotValidIntMove = true;
			userValidMove = optionalUserIntInput.value();
		}
	}

	return Move(userValidMove);
}


