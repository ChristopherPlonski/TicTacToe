#include <iostream>
#include <string>

#include "PyromancerArchetype.hpp"
#include "StringConverter.hpp"

PyromancerArchetype::PyromancerArchetype(char playerMarker, int playerNumber, const ArchetypeInfo& archetypeInfo, Board& boardReference) : ArchetypePlayer(playerMarker, playerNumber, archetypeInfo)
{
	this->board = &boardReference;
}

Move PyromancerArchetype::get_move()
{
	bool gotValidMove = false;
	Move userValidMove;

	while (!gotValidMove) {
		cout << get_move_prompt_text();
		cout << "- Input # to place marker on board\n";
		cout << "- Input \"ability\" to use your archetype ability: " << get_archetype_info().ARCHETYPE_ABILITY_DESCRIPTION << endl;

		string userStringInput;
		getline(cin, userStringInput);

		optional<int> optionalUserIntInput = StringConverter::try_get_int_from_string(userStringInput);

		if (!optionalUserIntInput.has_value()) {
			if (StringConverter::to_lowercase(userStringInput) == "ability") {
				if (can_use_ability()) {
					gotValidMove = true;
					usedAbility = true;
					activate_ability();
					userValidMove = Move();
				}
				else {
					cout << "Cannot use ability as it is alread used this game!\n";
				}
				// TODO: Add checks and variables for "usedAbility" to prevent infinitely using ability
			}
			else {
				cout << "Provided input was not a valid move.\n";
			}
		}
		else {
			gotValidMove = true;
			userValidMove = Move(optionalUserIntInput.value());
		}
	}

	return userValidMove;
}

bool PyromancerArchetype::can_use_ability()
{
	// If usedAbility is true, that means you shouldn't be able to use the ability anymore as this is a 1 time use ability.
	return !usedAbility;
}

void PyromancerArchetype::activate_ability()
{
	// Pyromancer ability is to clear the whole board, which is pretty simple to do.
	board->clear_board();
}


