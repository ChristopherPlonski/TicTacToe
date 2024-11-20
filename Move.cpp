#include <iostream>
#include "Move.hpp"

Move::Move(int markPosition)
{
	this->optionalMarkPosition = optional<int>(markPosition);
	this->usedTurnEndingAbility = false;
}

Move::Move()
{
	this->optionalMarkPosition = optional<int>();
	this->usedTurnEndingAbility = true;
}

optional<int> Move::get_optional_mark_position()
{
	return optionalMarkPosition;
}

bool Move::used_turn_ending_ability()
{
	return this->usedTurnEndingAbility;
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
