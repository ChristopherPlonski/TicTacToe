#include <cassert>
#include <iostream>

#include "GamemodeInfo.hpp"

using namespace std;

int main() {
	cout << "--Testing GamemodeInfo." << endl;

	GamemodeInfo gamemode = GamemodeInfo(GamemodeInfo::GamemodeType::REGULAR, " TEsT! ", "t E S T 100");

	assert(gamemode.GAMEMODE_TYPE == GamemodeInfo::GamemodeType::REGULAR);
	assert(gamemode.GAMEMODE_TITLE == " TEsT! ");
	assert(gamemode.GAMEMODE_DESCRIPTION == "t E S T 100");

	cout << "--GamemodeInfo tests have passed!" << endl;
	return 0;
}