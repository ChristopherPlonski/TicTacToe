#include <iostream>
#include "Move.hpp"

Move::Move(int markPosition)
{
	this->optionalMarkPosition = optional<int>(markPosition);
	this->usedAbility = false;
}

Move::Move()
{
	this->optionalMarkPosition = optional<int>();
	this->usedAbility = true;
}

optional<int> Move::get_optional_mark_position()
{
	return optionalMarkPosition;
}

bool Move::used_ability()
{
	return this->usedAbility;
}
