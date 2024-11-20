#include <iostream>
#include <string>
#include <optional>

#include "HumanPlayer.hpp"
#include "StringConverter.hpp"

using namespace std;

HumanPlayer::HumanPlayer(char playerMarker, int playerNumber) : Player(playerMarker, playerNumber)
{

}

Move HumanPlayer::get_move() {
	bool gotValidIntMove = false;
	int userValidMove;

	while (!gotValidIntMove) {
		cout << "Player #" << Player::get_number() << " (" << Player::get_marker() << "), where do you want to make your mark? ";

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
