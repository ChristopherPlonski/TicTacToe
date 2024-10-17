#include <iostream>
#include <cassert>
#include "Console.hpp"
#include "Board.hpp"

using namespace std;

int main() {
	cout << "--Testing Console." << endl;
	Board board = Board();
	Console console = Console(&board);

	assert(console.display() == "+-----------+\n| 1 | 2 | 3 |\n+-----------+\n| 4 | 5 | 6 |\n+-----------+\n| 7 | 8 | 9 |\n+-----------+\n");
	board.mark_pos(1, 'X');
	assert(console.display() == "+-----------+\n| X | 2 | 3 |\n+-----------+\n| 4 | 5 | 6 |\n+-----------+\n| 7 | 8 | 9 |\n+-----------+\n");
	board.mark_pos(5, 'O');
	assert(console.display() == "+-----------+\n| X | 2 | 3 |\n+-----------+\n| 4 | O | 6 |\n+-----------+\n| 7 | 8 | 9 |\n+-----------+\n");

	cout << "--Console tests have passed!" << endl;
	return 0;
}