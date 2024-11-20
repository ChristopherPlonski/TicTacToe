#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <string>

using namespace std;

struct Gamemode {

public:
	enum class GamemodeType {
		REGULAR,
		BATTLE
	};

	Gamemode(GamemodeType gamemodeType, string gamemodeTitle, string gamemodeDescription);
	const GamemodeType GAMEMODE_TYPE;
	const string GAMEMODE_TITLE;
	const string GAMEMODE_DESCRIPTION;
};

#endif // !GAMEMODE_H