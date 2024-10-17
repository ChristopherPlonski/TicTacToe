#include <iostream>
#include <string>

#include "Validator.hpp"

Validator::Validator(Board* board)
{
	this->board = board;
}

// Checks if the string can be converted to an integer
optional<int> Validator::try_get_int_from_string(const string stringToConvert)
{
	int convertedIntFromString;

	try
	{
		// Convert string to int
		convertedIntFromString = stoi(stringToConvert);
	}
	catch (const invalid_argument& e)
	{
		return nullopt;
	}
	catch (const out_of_range& e)
	{
		return nullopt;
	}

	return convertedIntFromString;
}

int Validator::get_move()
{
	bool gotValidMove = false;
	int userValidMove;

	while (!gotValidMove) {
		cout << "Where do you want to make your mark? ";

		string userStringInput;
		getline(cin, userStringInput);

		optional<int> optionalUserIntInput = try_get_int_from_string(userStringInput);

		if (!optionalUserIntInput.has_value()) {
			cout << "Provided input was not a valid number. \n";
		}
		else if (!board->is_pos_in_board_bounds(optionalUserIntInput.value())) {
			cout << "Provided number (" << optionalUserIntInput.value() << ") is out of board bounds. \n";
		}
		else if (board->get_mark_at_pos(optionalUserIntInput.value()) != NULL) {
			cout << "Tile at number: " << optionalUserIntInput.value() << " is already occupied. \n";
		}
		else {
			// Valid input!
			gotValidMove = true;
			userValidMove = optionalUserIntInput.value();
		}
	}

	return userValidMove;
}
