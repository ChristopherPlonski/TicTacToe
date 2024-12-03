#include "SaveManager.hpp"

#include <iostream>

void SaveManager::save_game_report_to_file(GameStats &gameStats)
{
	json gameReportJSON = {
		{NUM_OF_GAMES_PLAYED_SAVE_STRING, gameStats.get_games_played()},
		{PLAYER_1_WINS_SAVE_STRING, gameStats.get_p1_wins()},
		{PLAYER_2_WINS_SAVE_STRING, gameStats.get_p2_wins()},
		{NUM_OF_DRAWS_SAVE_STRING, gameStats.get_draws()}
	};

	string jsonDump = gameReportJSON.dump();

	cout << "Test dump: " << jsonDump;
}
