#ifndef GAMEREPORTJSON_H
#define GAMEREPORTJSON_H

#include "GameStats.hpp"
#include "json.hpp"

using json = nlohmann::json;

class GameReportJSON {

public:
	string generate_game_report(GameStats& gameStats, bool makePretty);

private:
	const string NUM_OF_GAMES_PLAYED_JSON_STRING = "NumberOfGamesPlayed";
	const string PLAYER_1_WINS_JSON_STRING = "NumberOfTimesPlayer1Won";
	const string PLAYER_2_WINS_JSON_STRING = "NumberOfTimesPlayer2Won";
	const string NUM_OF_DRAWS_JSON_STRING = "NumberOfDraws";

};

#endif // !GAMEREPORTJSON_H
