#include "Console.hpp"
#include <iostream>

using namespace std;

Console::Console(Board* board)
{
	this->board = board;
}

string Console::display()
{
	string output = "";
	const int BOARD_SIZE = board->BOARD_SIZE;

	output += "+-----------+\n";
	for (int i = 0; i < BOARD_SIZE; i++) {

		for (int j = 0; j < BOARD_SIZE; j++) {
			int tileNumber = (i*3) + (j+1);
			//cout << "Checking tileNumber: " << tileNumber;
			if (j == 0) {
				output += "| ";
			}

			char markAtPos = board->get_mark_at_pos(tileNumber);
			string stringToDisplay;

			if (markAtPos == NULL) {
				stringToDisplay = to_string(tileNumber);
			}
			else {
				stringToDisplay = string(1, markAtPos);
			}

			output += stringToDisplay + " | ";
		}

		output += "\n+-----------+\n";
	}

	return output;
}
