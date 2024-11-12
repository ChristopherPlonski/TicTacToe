#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include "Board.hpp"

using namespace std;

class Console {

public:
	Console(Board &board);
	string display();

private:
	Board* board;
	string get_horizontal_separator() const;
	const string NEW_LINE_CORNER_PIECE = "+";
	const string HORIZONTAL_SYMBOL = "-";
	const string VERTICAL_SYMBOL = "|";
};

#endif // !CONSOLE_H