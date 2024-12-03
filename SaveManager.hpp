#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include <string>
#include "json.hpp"
#include "GameStats.hpp"

using namespace std;
using json = nlohmann::json;

class SaveManager {

public:
	void save_game_report_to_file(GameStats &gameStats);

private:
	const string NUM_OF_GAMES_PLAYED_SAVE_STRING = "NumberOfGamesPlayed";
	const string PLAYER_1_WINS_SAVE_STRING = "NumberOfTimesPlayer1Won";
	const string PLAYER_2_WINS_SAVE_STRING = "NumberOfTimesPlayer2Won";
	const string NUM_OF_DRAWS_SAVE_STRING = "NumberOfDraws";

};

#endif // !SAVEMANAGER_H
