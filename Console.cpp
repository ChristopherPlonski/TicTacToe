#include "Console.hpp"
#include <iostream>

using namespace std;

Console::Console(Board &board)
{
	this->board = &board;
}

/// <summary>
/// Returns a horizontal separator that scales with the grid size.
/// </summary>
/// <returns></returns>
string Console::get_horizontal_separator() const
{
	string horizontalSeparator = "";

	horizontalSeparator += NEW_LINE_CORNER_PIECE;

	// Dash formula: 3 dashes for each tile, and 1 dash for every vertical separator (AKA: boardSize - 1)
	for (int i = 0; i < board->BOARD_SIZE; i++) {
		horizontalSeparator += HORIZONTAL_SYMBOL + HORIZONTAL_SYMBOL + HORIZONTAL_SYMBOL;

		if (i > 0) {
			horizontalSeparator += HORIZONTAL_SYMBOL;
		}
	}

	horizontalSeparator += NEW_LINE_CORNER_PIECE;

	return horizontalSeparator;
}

string Console::display()
{
	string output = "";
	const int BOARD_SIZE = board->BOARD_SIZE;

	output += get_horizontal_separator()+"\n";
	for (int i = 0; i < BOARD_SIZE; i++) {

		for (int j = 0; j < BOARD_SIZE; j++) {
			int tileNumber = (i * BOARD_SIZE) + (j+1);
			//cout << "Checking tileNumber: " << tileNumber;
			if (j == 0) {
				output += VERTICAL_SYMBOL + " ";
			}

			char markAtPos = board->get_mark_at_pos(tileNumber);
			string stringToDisplay;

			if (markAtPos == NULL) {
				stringToDisplay = to_string(tileNumber);
			}
			else {
				stringToDisplay = string(1, markAtPos);
			}

			output += stringToDisplay + " " + VERTICAL_SYMBOL;

			if (j < BOARD_SIZE - 1) {
				output += " ";
			}
		}

		output += "\n" + get_horizontal_separator() + "\n";
	}

	return output;
}
