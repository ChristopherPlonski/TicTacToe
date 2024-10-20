#include <iostream>
#include <string>

#include "StringConverter.hpp"

// Checks if the string can be converted to an integer
optional<int> StringConverter::try_get_int_from_string(const string stringToConvert)
{
	try
	{
		// Convert string to int
		int convertedIntFromString = stoi(stringToConvert);

		return convertedIntFromString;
	}
	catch (const invalid_argument& e)
	{
		return nullopt;
	}
	catch (const out_of_range& e)
	{
		return nullopt;
	}

	return nullopt;
}

/// <summary>
/// Attempts to convert the provided string into a character. Will return 'nullopt' if string is empty, has more than 1 character, or the 1 character is a blank space.
/// </summary>
/// <param name="stringToConvert"></param>
/// <returns></returns>
optional<char> StringConverter::try_get_char_from_string(const string stringToConvert) {
	// Prevents converting a string that is empty or has more than 1 character.
	if (stringToConvert.size() == 0 || stringToConvert.size() > 1) {
		return nullopt;
	}

	// Prevents returning a blank space as a character
	if (stringToConvert[0] == ' ') {
		return nullopt;
	}

	return stringToConvert[0];
}