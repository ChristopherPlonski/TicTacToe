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

char HumanPlayer::prompt_for_marker(int playerNumber)
{
	bool gotValidMarker = false;
	char userValidMarker;

	while (!gotValidMarker) {
		cout << "Player #" << playerNumber << ", what do you want your marker to be (Req: 1 character, not blank, and unique): \n";

		string userStringInput;
		getline(cin, userStringInput);

		optional<char> optionalUserCharInput = StringConverter::try_get_char_from_string(userStringInput);

		if (!optionalUserCharInput.has_value()) {
			cout << "Provided input was not a valid marker. \n";
		}
		else {
			gotValidMarker = true;
			userValidMarker = optionalUserCharInput.value();
		}
	}

	return userValidMarker;
}

char HumanPlayer::prompt_for_new_marker()
{
	return HumanPlayer::prompt_for_marker(this->Player::get_number());
}
