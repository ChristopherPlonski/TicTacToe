#include "Gamemode.hpp"

Gamemode::Gamemode(GamemodeType gamemodeType, string gamemodeTitle, string gamemodeDescription)
{
	this->gamemodeType = gamemodeType;
	this->gamemodeTitle = gamemodeTitle;
	this->gamemodeDescription = gamemodeDescription;
}

Gamemode::GamemodeType Gamemode::get_gamemode_type()
{
	return this->gamemodeType;
}

string Gamemode::get_gamemode_title()
{
	return this->gamemodeTitle;
}

string Gamemode::get_gamemode_description()
{
	return this->gamemodeDescription;
}


