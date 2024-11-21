#include <iostream>

#include "ArchetypeInfoHandler.hpp"
#include "StringConverter.hpp"

using namespace std;

ArchetypeInfoHandler::ArchetypeInfoHandler() : ARCHETYPE_INFOS_ARRAY{
	ArchetypeInfo(ArchetypeInfo::ArchetypeType::PYROMANCER, "Pyromancer", "Burn the whole board alive!", "Clear the whole board. Uses up your turn."),
	ArchetypeInfo(ArchetypeInfo::ArchetypeType::SWARM, "Swarm", "Use the corners to your advantage!", "Non-useable. Gain the ability to win with the 4 corners.")
}
{

}

ArchetypeInfo::ArchetypeType ArchetypeInfoHandler::get_user_to_pick_archetype_type()
{
	bool gotValidArchetype = false;
	const ArchetypeInfo* chosenArchetypeInfo = &ARCHETYPE_INFOS_ARRAY[0]; // Default.

	while (!gotValidArchetype) {
		cout << "Choose one of the archetypes (type their respective number to choose it).\n";

		for (int i = 0; i < NUMBER_OF_ARCHETYPES; i++) {
			ArchetypeInfo archetype = ARCHETYPE_INFOS_ARRAY[i];
			const int NUMBER_REPRESENTING_ARCHETYPE = i + 1;

			cout << "[" << NUMBER_REPRESENTING_ARCHETYPE << "] - " << archetype.ARCHETYPE_NAME << " | " << archetype.ARCHETYPE_DESCRIPTION << endl;
			cout << "\t - Ability: " << archetype.ARCHETYPE_ABILITY_DESCRIPTION << endl;
		}

		string userResponse;

		getline(cin, userResponse);
		optional<int> optionalUserInt = StringConverter::try_get_int_from_string(userResponse);

		if (!optionalUserInt.has_value()) {
			cout << "Input was not a number. Please type one of the archetype's numbers.\n";
		}
		else if (optionalUserInt.value() < 1 || optionalUserInt.value() > NUMBER_OF_ARCHETYPES) {
			cout << "Input was not one of the displayed archetypes' numbers. Try again.\n";
		}
		else {
			// User input was valid! 
			int chosenArchetypeIndex = optionalUserInt.value() - 1;
			chosenArchetypeInfo = &ARCHETYPE_INFOS_ARRAY[chosenArchetypeIndex];
			gotValidArchetype = true;
		}
	}

	cout << "You chose archetype: " << chosenArchetypeInfo->ARCHETYPE_NAME << endl;

	ArchetypeInfo::ArchetypeType chosenArchetypeType = chosenArchetypeInfo->ARCHETYPE_TYPE;

	return chosenArchetypeType;
}
