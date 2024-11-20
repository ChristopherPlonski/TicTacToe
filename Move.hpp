#ifndef MOVE_H
#define MOVE_H

#include <optional>
#include <ostream>

using namespace std;

class Move {

public:
	/// <summary>
	/// For if the player only makes a markPosition. usedTurnEndingAbility still false.
	/// </summary>
	/// <param name="optionalMarkPosition"></param>
	explicit Move(int markPosition);
	/// <summary>
	/// Assumes the player used an ability as a turn-ending move. Sets usedTurnEndingAbility to true.
	/// </summary>
	explicit Move();
	optional<int> get_optional_mark_position();
	bool used_turn_ending_ability();

	// Overloading the << operator
	friend ostream& operator<<(ostream& os, const Move& move);

private:
	optional<int> optionalMarkPosition;
	bool usedTurnEndingAbility;
};

#endif // !MOVE_H
