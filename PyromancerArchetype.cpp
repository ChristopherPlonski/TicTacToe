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


pair<optional<Move>, InvalidInput*> PyromancerArchetype::try_get_move_from_input(string input)
{
	optional<int> optionalMarkMoveInput = StringConverter::try_get_int_from_string(input);

	if (!optionalMarkMoveInput.has_value()) {
		// Input is a string, so try to use ability.
		pair<bool, InvalidInput*> usedAbility = try_use_ability_from_input(input);
		bool wasAbilityUsageSuccessful = usedAbility.first;

		if (!wasAbilityUsageSuccessful) {
			// Ability could not be used.
			InvalidInput* invalidAbilityUsageInput = usedAbility.second;
			return pair<optional<Move>, InvalidInput*>(nullopt, invalidAbilityUsageInput);
		}

		// Ability was successfully used.
		Move abilityMove = Move();
		return pair<optional<Move>, InvalidInput*>(abilityMove, nullptr);
	}

	// Input is an int, so a mark move was made.
	int markMoveInput = optionalMarkMoveInput.value();
	Move userMarkMove = Move(markMoveInput);

	return pair<optional<Move>, InvalidInput*>(userMarkMove, nullptr);
}


pair<bool, InvalidInput*> PyromancerArchetype::try_use_ability_from_input(string input)
{
	if (StringConverter::to_lowercase(input) != "ability") {
		// User input is something else than trying to use ability.
		return pair<bool, InvalidInput*>(false, new InvalidInput());
	}

	if (!can_use_ability()) {
		// Ability cannot be used right now.
		//cout << "\n -Debug AbilityUsedII: " << AbilityUsedInvalidInput().message() << endl;
		return pair<bool, InvalidInput*>(false, new AbilityUsedInvalidInput());
	}

	// Can use ability!
	activate_ability();
	usedAbility = true;

	return pair<bool, InvalidInput*>(true, nullptr);
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


