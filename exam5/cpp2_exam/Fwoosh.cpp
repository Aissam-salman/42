#include "Fwoosh.hpp"
#include "ASpell.hpp"

Fwoosh::Fwoosh(void): ASpell("Fwoosh", "fwooshed") {}

Fwoosh::Fwoosh(std::string name, std::string effects): ASpell(name, effects) {}

Fwoosh::Fwoosh(const Fwoosh &src): ASpell(src) { }

Fwoosh &Fwoosh::operator=(const Fwoosh &rhs) {
	if (this != &rhs)
		ASpell::operator=(rhs);
	return *this;
}

Fwoosh::~Fwoosh(void) {}

Fwoosh *Fwoosh::clone(void) const {
	return new Fwoosh(this->name, this->effects);
}

