#include "Player.hpp"

Player::Player(char playerMarker, int playerNumber)
{
	this->playerMarker = playerMarker;
	this->playerNumber = playerNumber;
}

//void Player::set_player_marker(char playerMarker)
//{
//	this->playerMarker = playerMarker;
//}
//
//void Player::set_player_number(int playerNumber)
//{
//	this->playerNumber = playerNumber;
//}

char Player::get_marker()
{
	return this->playerMarker;
}

int Player::get_number()
{
	return this->playerNumber;
}

string Player::get_move_prompt_text()
{
	return "Player #" + to_string(this->playerNumber) + " (" + this->playerMarker + "), what do you want your move to be?";
}
