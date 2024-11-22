#include <iostream>

#include "ArchetypeInfoHandler.hpp"
#include "StringConverter.hpp"

using namespace std;

ArchetypeInfoHandler::ArchetypeInfoHandler() : ARCHETYPE_INFOS_ARRAY{
	ArchetypeInfo(ArchetypeInfo::ArchetypeType::PYROMANCER, "Pyromancer", "Having struggles with your enemy? Fry them alive!", "Clear the whole board. Uses up your turn."),
	ArchetypeInfo(ArchetypeInfo::ArchetypeType::SWARM, "Swarm", "Use the corners of the board to your advantage!", "Passive. Gain the ability to win with the 4 corners.")
}
{

}

ArchetypeInfo ArchetypeInfoHandler::get_user_to_pick_archetype()
{
	bool gotValidArchetype = false;
	const ArchetypeInfo* chosenArchetypeInfo = &ARCHETYPE_INFOS_ARRAY[0]; // Default.

	while (!gotValidArchetype) {
		cout << "* Choose one of the archetypes (input their respective number to choose it).\n";

		for (int i = 0; i < NUMBER_OF_ARCHETYPES; i++) {
			ArchetypeInfo archetype = ARCHETYPE_INFOS_ARRAY[i];
			const int NUMBER_REPRESENTING_ARCHETYPE = i + 1;

			cout << "* [" << NUMBER_REPRESENTING_ARCHETYPE << "] - " << archetype.ARCHETYPE_NAME << " | " << archetype.ARCHETYPE_DESCRIPTION << endl;
			cout << "\t - Ability: " << archetype.ARCHETYPE_ABILITY_DESCRIPTION << endl;
		}

		string userResponse;

		getline(cin, userResponse);
		optional<int> optionalUserInt = StringConverter::try_get_int_from_string(userResponse);

		if (!optionalUserInt.has_value()) {
			cout << "Input was not a number. Please input one of the archetype's numbers.\n\n";
		}
		else if (optionalUserInt.value() < 1 || optionalUserInt.value() > NUMBER_OF_ARCHETYPES) {
			cout << "Input was not one of the displayed archetypes' numbers. Try again.\n\n";
		}
		else {
			// User input was valid! 
			int chosenArchetypeIndex = optionalUserInt.value() - 1;
			chosenArchetypeInfo = &ARCHETYPE_INFOS_ARRAY[chosenArchetypeIndex];
			gotValidArchetype = true;
		}
	}

	cout << "You chose archetype: " << chosenArchetypeInfo->ARCHETYPE_NAME << endl << endl;

	return *chosenArchetypeInfo;
}

ArchetypeInfo ArchetypeInfoHandler::get_archetype_info_from_archetype_type(ArchetypeInfo::ArchetypeType archetypeType)
{
	for (int i = 0; i < NUMBER_OF_ARCHETYPES; i++) {
		ArchetypeInfo archetypeInfo = ARCHETYPE_INFOS_ARRAY[i];

		if (archetypeInfo.ARCHETYPE_TYPE == archetypeType) {
			return archetypeInfo;
		}
	}

	cerr << "WARNING: No ArchetypeInfo found with ArchetypeType value: " << (int)archetypeType;
	return ARCHETYPE_INFOS_ARRAY[0]; // Default.
}
