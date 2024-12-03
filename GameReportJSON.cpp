#include "GameReportJSON.hpp"

string GameReportJSON::generate_game_report(GameStats& gameStats, bool makePretty)
{
	json gameReportJSON = {
		{NUM_OF_GAMES_PLAYED_JSON_STRING, gameStats.get_games_played()},
		{PLAYER_1_WINS_JSON_STRING, gameStats.get_p1_wins()},
		{PLAYER_2_WINS_JSON_STRING, gameStats.get_p2_wins()},
		{NUM_OF_DRAWS_JSON_STRING, gameStats.get_draws()}
	};

	string jsonDump;

	if (makePretty) {
		jsonDump = gameReportJSON.dump(4);
	}
	else {
		jsonDump = gameReportJSON.dump();
	}

	// Not needed, just add integer amount argument to the dump() method
	/*if (makePretty) {
		string prettyJsonDump;

		for (int i = 0; i < jsonDump.length(); i++) {
			char charAtIndex = jsonDump[i];

			string stringToAdd = string(1, charAtIndex);

			if (charAtIndex == ',' || charAtIndex == '{') {
				stringToAdd = stringToAdd + '\n';
			}
			else if (charAtIndex == '}') {
				stringToAdd = '\n' + stringToAdd;
			}

			prettyJsonDump += stringToAdd;
		}

		jsonDump = prettyJsonDump;
	}*/

	return jsonDump;
}
