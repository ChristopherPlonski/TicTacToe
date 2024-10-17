#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <optional>
#include "Board.hpp"

using namespace std;

class Validator {

public:
	Validator(Board* board);
	int get_move();
private:
	Board* board;
	optional<int> try_get_int_from_string(const string stringToConvert);
};

#endif // !VALIDATOR_H