#ifndef MARKERVALIDATOR_H
#define MARKERVALIDATOR_H

#include <vector>

using namespace std;

class MarkerValidator {

public:
	char get_valid_marker_for_human_player(int playerNumber, char allPlayerMarkersArray[], int numOfPlayers);
private:
	bool is_player_marker_unique(char playerMarker, char allPlayerMarkersArray[], int numOfPlayers);
	char prompt_player_for_marker(int playerNumber);
};

#endif // !MARKERVALIDATOR_H
