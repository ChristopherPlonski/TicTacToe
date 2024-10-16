#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include "Board.hpp"

using namespace std;

class Console {

public:
	Console(Board *board);
	string display();

private:
	Board* board;
};

#endif // !CONSOLE_H