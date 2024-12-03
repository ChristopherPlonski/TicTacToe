#ifndef GAMESTATS_H
#define GAMESTATS_H

#include "GameState.hpp"

class GameStats {

public:
	void report_game_played(GameState::State gameResult);
	
	int get_games_played();
	int get_p1_wins();
	int get_p2_wins();
	int get_draws();

private:
	int gamesPlayedTotal;
	int player1WinsTotal;
	int player2WinsTotal;
	int drawsTotal;

};

#endif // !GAMESTATS_H
