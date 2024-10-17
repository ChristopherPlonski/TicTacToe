#include <iostream>
#include <string>
#include <optional>

#include "Player.hpp"
#include "Validator.hpp"
#include "StringConverter.hpp"

using namespace std;

Player::Player(char playerMarker, Board* board)
{
	this->playerMarker = playerMarker;
	this->board = board;
}

int Player::get_move() {
	bool gotValidMove = false;
	int userValidMove;

	while (!gotValidMove) {
		cout << "Where do you want to make your mark? ";

		string userStringInput;
		getline(cin, userStringInput);

		optional<int> optionalUserIntInput = StringConverter::try_get_int_from_string(userStringInput);

		if (!optionalUserIntInput.has_value()) {
			cout << "Provided input was not a valid number. \n";
		}
		else {
			bool isIntInputValid = Validator::is_user_move_input_valid(optionalUserIntInput.value(), board);

			if(!isIntInputValid){
				// Do nothing, user was already notified.
			}
			else {
				// Valid input!
				gotValidMove = true;
				userValidMove = optionalUserIntInput.value();
			}
		}
	}

	return userValidMove;
}