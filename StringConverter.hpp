#ifndef STRINGCONVERTER_H
#define STRINGCONVERTER_H

#include <optional>

using namespace std;

class StringConverter {

public:
	static optional<int> try_get_int_from_string(const string stringToConvert);
	static optional<char> try_get_char_from_string(const string stringToConvert);
	static string to_lowercase(const string stringToConvert);
};

#endif // !STRINGCONVERTER_H
