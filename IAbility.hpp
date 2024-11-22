#ifndef IABILITY_H
#define IABILITY_H

class IAbility {

protected:
	virtual bool can_use_ability() = 0;
	virtual void activate_ability() = 0;
};

#endif // !IAbility
