#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

#include <string>

class InvalidInput {

public:
	virtual std::string message() {
		return "Invalid input.";
	}

};

#endif // !INVALIDINPUT_H
