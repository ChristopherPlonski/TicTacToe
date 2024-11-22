#ifndef IABILITY_H
#define IABILITY_H

#include <utility>
#include <optional>

#include "InvalidInput.hpp"

using namespace std;

class IAbility {

protected:
	virtual pair<bool, optional<InvalidInput>> try_use_ability_from_input(string input) = 0;
	virtual bool can_use_ability() = 0;
	virtual void activate_ability() = 0;
};

#endif // !IAbility
