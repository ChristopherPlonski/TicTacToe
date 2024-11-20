#ifndef MARKERVALIDATOR_H
#define MARKERVALIDATOR_H

#include <vector>

#include "BasicPlayer.hpp"

using namespace std;

class MarkerValidator {

public:
	char get_valid_marker_for_human_player(int playerNumber, vector<Player*>* allPlayersVector);
private:
	bool is_player_marker_unique(char playerMarker, Player* playerOfMarkerToCheck, vector<Player*>* allPlayersVector);
	char prompt_player_for_marker(int playerNumber);
};

#endif // !MARKERVALIDATOR_H
