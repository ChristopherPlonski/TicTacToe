#include <cassert>
#include <iostream>
#include <string>
#include "Validator.hpp"

using namespace std;

int main() {
	cout << "--Testing Validator \n";

	Board board = Board();
	Validator validator = Validator(&board);

	bool isTesting = true;
	while (isTesting) {
		cout << "\n Testing board with size 3x3. \n";
		int userMove = validator.get_move();
		cout << "User inputted move: " << userMove << endl;

		string userInput;
		cout << "Exit test? ('exit' to exit): ";
		getline(cin, userInput);

		if (userInput == "exit") {
			isTesting = false;
		}
	}


	cout << "--Validator tests have passed! \n";
	return 0;
}