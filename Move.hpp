#ifndef MOVE_H
#define MOVE_H

#include <optional>

using namespace std;

class Move {

public:
	/// <summary>
	/// For if the player only makes a markPosition. usedAbility still false.
	/// </summary>
	/// <param name="optionalMarkPosition"></param>
	explicit Move(int markPosition);
	/// <summary>
	/// Assumes the player used an ability as a move. Sets usedAbility to true.
	/// </summary>
	explicit Move();
	optional<int> get_optional_mark_position();
	bool used_ability();

private:
	optional<int> optionalMarkPosition;
	bool usedAbility;
};

#endif // !MOVE_H
