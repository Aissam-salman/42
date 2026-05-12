#include "ATarget.hpp"
#include "ASpell.hpp"
#include <string>
#include <iostream>

ATarget::ATarget(void): type("") {}

ATarget::ATarget(std::string type): type(type) {}

ATarget::ATarget(const ATarget &src) { *this = src; }

ATarget &ATarget::operator=(const ATarget &rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

ATarget::~ATarget(void) {}

std::string &ATarget::getType(void) const {
	return const_cast<std::string &>(this->type);
}

void ATarget::getHitBySpell(const ASpell &spell) const {
	std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}




