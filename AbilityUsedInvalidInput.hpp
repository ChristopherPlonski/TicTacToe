#ifndef ABILITYUSEDINVALIDINPUT_H
#define ABILITYUSEDINVALIDINPUT_H

#include "InvalidInput.hpp"

class AbilityUsedInvalidInput : public InvalidInput {

public:
	 std::string message() override {
		return "Ability already used.";
	}

};

#endif // !ABILITYUSEDINVALIDINPUT_H
