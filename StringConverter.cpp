#include <iostream>
#include <string>

#include "StringConverter.hpp"

// Checks if the string can be converted to an integer
optional<int> StringConverter::try_get_int_from_string(const string stringToConvert)
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