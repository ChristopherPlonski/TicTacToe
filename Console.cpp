#include "Console.hpp"

Console::Console(Board* board)
{
	this->board = board;
}

string Console::display()
{
	string output = "";

	output += "1 | 2 | 3 \n ----------- \n 4 | 5 | 6 \n ----------- \n 7 | 8 | 9 \n";

	return output;
}
