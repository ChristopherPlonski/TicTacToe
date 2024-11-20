#include <iostream>
#include <string>

#include "MarkerValidator.hpp"
#include "StringConverter.hpp"

using namespace std;

char MarkerValidator::get_valid_marker_for_human_player(int playerNumber, vector<Player*>* allPlayersVector)
{
	bool gotValidMarker = false;
	char validPlayerMarker;

	while (!gotValidMarker) {
		char markerFromPlayer = prompt_player_for_marker(playerNumber);

		bool isPlayerMarkerUnique = is_player_marker_unique(markerFromPlayer, NULL, allPlayersVector);

		if (!isPlayerMarkerUnique) {
			cout << "Provided marker is taken by another player! \n";
		}
		else {
			gotValidMarker = true;
			validPlayerMarker = markerFromPlayer;
		}
	}

	return validPlayerMarker;
}

char MarkerValidator::prompt_player_for_marker(int playerNumber)
{
	bool gotValidMarker = false;
	char userValidMarker;

	while (!gotValidMarker) {
		cout << "Player #" << playerNumber << ", what do you want your marker to be (Req: 1 character, not blank, and unique): \n";

		string userStringInput;
		getline(cin, userStringInput);

		optional<char> optionalUserCharInput = StringConverter::try_get_char_from_string(userStringInput);

		if (!optionalUserCharInput.has_value()) {
			cout << "Provided input was not a valid marker. \n";
		}
		else {
			gotValidMarker = true;
			userValidMarker = optionalUserCharInput.value();
		}
	}

	return userValidMarker;
}


bool MarkerValidator::is_player_marker_unique(char playerMarker, Player* playerOfMarkerToCheck, vector<Player*>* allPlayersVector)
{
	for (int i = 0; i < allPlayersVector->size(); i++) {
		Player* playerToCheck = allPlayersVector->at(i);

		if (playerToCheck != playerOfMarkerToCheck) {
			char otherPlayerMarker = playerToCheck->get_marker();
			//cout << "Checking Player #" << i+1 << endl;
			if (playerMarker == otherPlayerMarker) {
				return false;
			}
		}
	}

	return true;
}