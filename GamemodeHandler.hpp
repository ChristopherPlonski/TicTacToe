#ifndef GAMEMODEHANDLER_H
#define GAMEMODEHANDLER_H

#include <array>

#include "GamemodeInfo.hpp"

using namespace std;

class GamemodeHandler {

public:
	static const int NUMBER_OF_GAMEMODES = 2;

	GamemodeHandler();
	GamemodeInfo::GamemodeType get_user_to_pick_gamemode_type();

private:
	const array<GamemodeInfo, NUMBER_OF_GAMEMODES> GAMEMODES_ARRAY;
};

#endif // !GAMEMODEHANDLER_H
