#include <iostream>
#include <string>
#include <optional>

#include "Player.hpp"
#include "StringConverter.hpp"

using namespace std;

Player::Player(char playerMarker, int playerNumber, Board* board)
{
	this->playerMarker = playerMarker;
	this->playerNumber = playerNumber;
	this->board = board;
}

int Player::get_move() {
	bool gotValidIntMove = false;
	int userValidMove;

	while (!gotValidIntMove) {
		cout << "Player #" << playerNumber << ", where do you want to make your mark? ";

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

	return userValidMove;
}

char Player::get_marker()
{
	return this->playerMarker;
}
