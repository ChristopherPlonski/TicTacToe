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
	GamemodeType get_gamemode_type();
	string get_gamemode_title();
	string get_gamemode_description();

private:
	GamemodeType gamemodeType;
	string gamemodeTitle;
	string gamemodeDescription;
};

#endif // !GAMEMODE_H