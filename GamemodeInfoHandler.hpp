#ifndef GAMEMODEINFOHANDLER_H
#define GAMEMODEINFOHANDLER_H

#include <array>

#include "GamemodeInfo.hpp"

using namespace std;

class GamemodeInfoHandler {

public:
	static const int NUMBER_OF_GAMEMODES = 2;

	GamemodeInfoHandler();
	GamemodeInfo::GamemodeType get_user_to_pick_gamemode_type();

private:
	const array<GamemodeInfo, NUMBER_OF_GAMEMODES> GAMEMODE_INFOS_ARRAY;
};

#endif // !GAMEMODEINFOHANDLER_H
