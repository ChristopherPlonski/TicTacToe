#include <string>
#include <optional>

#include "BasicPlayer.hpp"
#include "StringConverter.hpp"

using namespace std;

BasicPlayer::BasicPlayer(char playerMarker, int playerNumber) : 
	Player(playerMarker, playerNumber)
{

}

const Player::WinMarkCombination* BasicPlayer::get_win_mark_combinations_array() const
{
	return new WinMarkCombination[3]{
		WinMarkCombination::ROWS,
		WinMarkCombination::COLUMNS,
		WinMarkCombination::DIAGONALS
	};
}

string BasicPlayer::get_move_prompt_text()
{
	string basePromptText = Player::get_move_prompt_text();
	string boardMovePromptText = "- Input # to place marker on board\n";

	string entirePromptText = basePromptText + boardMovePromptText;
	return entirePromptText;
}

pair<optional<Move>, InvalidInput*> BasicPlayer::try_get_move_from_input(string input)
{
	optional<int> optionalUserMarkMoveInput = StringConverter::try_get_int_from_string(input);

	if (!optionalUserMarkMoveInput.has_value()) {
		return pair<optional<Move>, InvalidInput*>(nullopt, new InvalidInput());
	}

	int userMarkMoveInput = optionalUserMarkMoveInput.value();
	Move userMarkMove = Move(userMarkMoveInput);

	return pair<optional<Move>, InvalidInput*>(userMarkMove, nullptr);
}