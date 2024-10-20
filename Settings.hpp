#ifndef SETTINGS_H
#define SETTINGS_H

#include <vector>

#include "HumanPlayer.hpp"

using namespace std;

class Settings {

public:
	char get_valid_marker_from_human_player(HumanPlayer* playerToGetMarkerFor, vector<Player*>* allPlayersVector);
	char get_valid_marker_for_human_player(int playerNumber, vector<Player*>* allPlayersVector);
private:
	bool is_player_marker_unique(char playerMarker, Player* playerOfMarkerToCheck, vector<Player*>* allPlayersVector);

};

#endif // !SETTINGS_H
