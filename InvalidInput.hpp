#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

#include <string>

class InvalidInput {

public:
	const virtual std::string message() const {
		return "Invalid input.";
	}

};

#endif // !INVALIDINPUT_H
