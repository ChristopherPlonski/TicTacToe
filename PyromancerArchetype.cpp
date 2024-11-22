//#include <iostream>
#include <string>

#include "PyromancerArchetype.hpp"
#include "StringConverter.hpp"
#include "AbilityUsedInvalidInput.hpp"

PyromancerArchetype::PyromancerArchetype(char playerMarker, int playerNumber, const ArchetypeInfo& archetypeInfo, Board& boardReference) : ArchetypePlayer(playerMarker, playerNumber, archetypeInfo)
{
	this->board = &boardReference;
}

string PyromancerArchetype::get_move_prompt_text()
{
	string basePromptText = ArchetypePlayer::get_move_prompt_text();
	string abilityPromptText = "- Input \"ability\" to use your archetype ability: " + get_archetype_info().ARCHETYPE_ABILITY_DESCRIPTION + "\n";

	string entirePromptText = basePromptText + abilityPromptText;
	return entirePromptText;
}


pair<optional<Move>, optional<InvalidInput>> PyromancerArchetype::try_get_move_from_input(string input)
{
	optional<int> optionalMarkMoveInput = StringConverter::try_get_int_from_string(input);

	if (!optionalMarkMoveInput.has_value()) {
		// Input is a string, so try to use ability.
		pair<bool, optional<InvalidInput>> usedAbility = try_use_ability_from_input(input);

		if (!usedAbility.first) {
			// Ability could not be used.
			// ---------------------------------------------------------------------------------- CURRENT ISSUE: If a AbilityUsedInvalidInput is passed as an InvalidInput, it still only prints out the InvalidInput's message.
			// ---------------------------------------------------------------------------------- Shouldn't this not be happening because of runtime polymorphism? Do I need to pass it as a pointer instead?
			//cout << "\n -Debug AbilityUsedII Inner: " << usedAbility.second.value().message() << endl;
			return pair<optional<Move>, optional<InvalidInput>>(nullopt, usedAbility.second);
		}

		// Ability was successfully used.
		Move abilityMove = Move();
		return pair<optional<Move>, optional<InvalidInput>>(abilityMove, nullopt);
	}

	// Input is an int, so a mark move was made.
	int markMoveInput = optionalMarkMoveInput.value();
	Move userMarkMove = Move(markMoveInput);

	return pair<optional<Move>, optional<InvalidInput>>(userMarkMove, nullopt);
}

pair<bool, optional<InvalidInput>> PyromancerArchetype::try_use_ability_from_input(string input)
{
	if (StringConverter::to_lowercase(input) != "ability") {
		// User input is something else than trying to use ability.
		return pair<bool, optional<InvalidInput>>(false, InvalidInput());
	}

	if (!can_use_ability()) {
		// Ability cannot be used right now.
		//cout << "\n -Debug AbilityUsedII: " << AbilityUsedInvalidInput().message() << endl;
		return pair<bool, optional<InvalidInput>>(false, AbilityUsedInvalidInput());
	}

	// Can use ability!
	activate_ability();
	usedAbility = true;

	return pair<bool, optional<InvalidInput>>(true, nullopt);
}

bool PyromancerArchetype::can_use_ability()
{
	// If usedAbility, then you shouldn't be able to use the ability anymore as this is a 1 time use ability.
	return !usedAbility;
}

void PyromancerArchetype::activate_ability()
{
	board->clear_board();
}


