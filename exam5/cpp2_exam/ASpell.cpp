#include "ASpell.hpp"
#include <string>

ASpell::ASpell(void): name(""), effects("") {}

ASpell::ASpell(std::string name, std::string effects): name(name), effects(effects) {}

ASpell::ASpell(const ASpell &src) { *this = src; }

ASpell &ASpell::operator=(const ASpell &rhs) {
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->effects = rhs.effects;
	}
	return *this;
}

ASpell::~ASpell(void) {}


std::string &ASpell::getName(void) const {
	return const_cast<std::string &>(this->name);
}


std::string &ASpell::getEffects(void) const {
	return const_cast<std::string &>(this->effects);
}

void ASpell::launch(const ATarget &target) const {
	target.getHitBySpell(*this);
}


