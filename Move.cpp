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

ostream& operator<<(ostream& os, const Move& move)
{
	os << "Move: ";
	if (move.optionalMarkPosition.has_value()) {
		os << "Mark @ " << move.optionalMarkPosition.value();
	}
	else {
		os << "Used ability";
	}

	return os;
}
