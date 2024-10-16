#include <iostream>
#include <cassert>
#include "Console.hpp"
#include "Board.hpp"

using namespace std;

int main() {
	cout << "--Testing Console." << endl;
	Board board = Board();
	Console console = Console(&board);

	assert(console.display() == "1 | 2 | 3 \n ----------- \n 4 | 5 | 6 \n ----------- \n 7 | 8 | 9 \n");

	cout << "--Console tests have passed!" << endl;
	return 0;
}