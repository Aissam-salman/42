#include "Dummy.hpp"
#include "ATarget.hpp"
#include <string>
#include <iostream>

Dummy::Dummy(void): ATarget("Target Pratice Dummy")  {}

Dummy::Dummy(std::string type): ATarget(type) {}

Dummy::Dummy(const Dummy &src): ATarget(src) {
}

Dummy &Dummy::operator=(const Dummy &rhs) {
	if (this != &rhs)
		ATarget::operator=(rhs);
	return *this;
}

Dummy::~Dummy(void) {}

Dummy *Dummy::clone(void) const {
	return new Dummy(this->type);
}
