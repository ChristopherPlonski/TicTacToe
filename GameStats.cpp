#include "GameStats.hpp"

#include <iostream>

void GameStats::report_game_played(GameState::State gameResult)
{
	this->gamesPlayedTotal++;

	switch (gameResult)
	{
	case GameState::State::Player1Win:
		this->player1WinsTotal++;
		break;
	case GameState::State::Player2Win:
		this->player2WinsTotal++;
		break;
	case GameState::State::Draw:
		this->drawsTotal++;
		break;
	case GameState::State::InProgress:
		cerr << "Invalid GameState::State gameResult: InProgress.";
		throw runtime_error("Invalid GameState::State gameResult: InProgress.");
		break;
	default:
		cerr << "No implementation for GameState::State gameResult: " << (int)gameResult;
		break;
	}
}

int GameStats::get_games_played()
{
	return this->gamesPlayedTotal;
}

int GameStats::get_p1_wins()
{
	return this->player1WinsTotal;
}

int GameStats::get_p2_wins()
{
	return this->player2WinsTotal;
}

int GameStats::get_draws()
{
	return this->drawsTotal;
}
