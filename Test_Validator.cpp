#include <cassert>
#include <iostream>
#include <string>
#include "Validator.hpp"

using namespace std;

int main() {
	cout << "--Testing Validator \n";

	Board board = Board();

	bool isTesting = true;
	while (isTesting) {
		cout << "\n Testing board with size 3x3. \n";
		int userMove = Validator::is_user_move_input_valid(1, board);
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