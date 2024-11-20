#ifndef GAMEMODEINFO_H
#define GAMEMODEINFO_H

#include <string>

using namespace std;

struct GamemodeInfo {

public:
	enum class GamemodeType {
		REGULAR,
		BATTLE
	};

	GamemodeInfo(GamemodeType gamemodeType, string gamemodeTitle, string gamemodeDescription);
	const GamemodeType GAMEMODE_TYPE;
	const string GAMEMODE_TITLE;
	const string GAMEMODE_DESCRIPTION;
};

#endif // !GAMEMODEINFO_H