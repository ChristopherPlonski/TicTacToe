#include <cassert>
#include <iostream>

#include "Gamemode.hpp"

using namespace std;

int main() {
	cout << "--Testing Gamemode." << endl;

	Gamemode gamemode = Gamemode(Gamemode::GamemodeType::REGULAR, " TEsT! ", "t E S T 100");

	assert(gamemode.GAMEMODE_TYPE == Gamemode::GamemodeType::REGULAR);
	assert(gamemode.GAMEMODE_TITLE == " TEsT! ");
	assert(gamemode.GAMEMODE_DESCRIPTION == "t E S T 100");

	cout << "--Gamemode tests have passed!" << endl;
	return 0;
}