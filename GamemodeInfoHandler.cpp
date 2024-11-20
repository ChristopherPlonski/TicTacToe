#include <iostream>

#include "GamemodeInfoHandler.hpp"
#include "StringConverter.hpp"

using namespace std;

GamemodeInfoHandler::GamemodeInfoHandler() : GAMEMODE_INFOS_ARRAY {
	GamemodeInfo(GamemodeInfo::GamemodeType::REGULAR, "Regular", "The classic game of Tic-Tac-Toe!"),
	GamemodeInfo(GamemodeInfo::GamemodeType::BATTLE, "Battle", "Use special archetypes to completely change the way you play!")
}
{

}

GamemodeInfo::GamemodeType GamemodeInfoHandler::get_user_to_pick_gamemode_type()
{
	bool gotValidGamemode = false;
	const GamemodeInfo* chosenGamemodeInfo = &GAMEMODE_INFOS_ARRAY[0]; // Default.

	while (!gotValidGamemode) {
		cout << "Choose one of the gamemodes (type their respective number to choose it).\n";

		for (int i = 0; i < NUMBER_OF_GAMEMODES; i++) {
			GamemodeInfo gamemode = GAMEMODE_INFOS_ARRAY[i];
			const int NUMBER_REPRESENTING_GAMEMODE = i + 1;

			cout << "[" << NUMBER_REPRESENTING_GAMEMODE << "] - " << gamemode.GAMEMODE_TITLE << " | " << gamemode.GAMEMODE_DESCRIPTION << endl;
		}

		string userResponse;

		getline(cin, userResponse);
		optional<int> optionalUserInt = StringConverter::try_get_int_from_string(userResponse);

		if (!optionalUserInt.has_value()) {
			cout << "Input was not a number. Please type one of the gamemode's numbers.\n";
		}
		else if (optionalUserInt.value() < 1 || optionalUserInt.value() > NUMBER_OF_GAMEMODES) {
			cout << "Input was not one of the displayed gamemodes' numbers. Try again.\n";
		}
		else {
			// User input was valid! 
			int chosenGamemodeIndex = optionalUserInt.value() - 1;
			chosenGamemodeInfo = &GAMEMODE_INFOS_ARRAY[chosenGamemodeIndex];
			gotValidGamemode = true;
		}
	}

	cout << "You chose gamemode: " << chosenGamemodeInfo->GAMEMODE_TITLE << endl;

	GamemodeInfo::GamemodeType chosenGamemodeType = chosenGamemodeInfo->GAMEMODE_TYPE;

	return chosenGamemodeType;
}
