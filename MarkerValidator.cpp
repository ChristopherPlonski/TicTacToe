#include "MarkerValidator.hpp"

#include <iostream>

char MarkerValidator::get_valid_marker_from_human_player(HumanPlayer* humanPlayerToGetMarkerFor, vector<Player*>* allPlayersVector)
{
	bool gotValidMarker = false;
	char validPlayerMarker;

	while (!gotValidMarker) {
		char markerFromPlayer = humanPlayerToGetMarkerFor->prompt_for_new_marker();
		
		bool isPlayerMarkerUnique = is_player_marker_unique(markerFromPlayer, humanPlayerToGetMarkerFor, allPlayersVector);

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

char MarkerValidator::get_valid_marker_for_human_player(int playerNumber, vector<Player*>* allPlayersVector)
{
	bool gotValidMarker = false;
	char validPlayerMarker;

	while (!gotValidMarker) {
		char markerFromPlayer = HumanPlayer::prompt_for_marker(playerNumber);

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
