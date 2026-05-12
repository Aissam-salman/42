
#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include <string>
#include <iostream>

Warlock::Warlock(void): name(""), title("") {}

Warlock::Warlock(const Warlock &src) { *this = src;}

Warlock &Warlock::operator=(const Warlock &rhs) { 
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->title = rhs.title;
	}
	return *this;
}

Warlock::~Warlock(void){
	std::cout << this->name << ": My job here is done!" << std::endl;
	
	std::vector<ASpell *>::iterator it = this->_spells.begin();
	std::vector<ASpell *>::iterator ite = this->_spells.end();
	for (; it != ite; ++it) {
		delete *it;
	}
	this->_spells.clear();
}

Warlock::Warlock(std::string name, std::string title): name(name), title(title) {
	std::cout << name << ": This looks like another boring day." << std::endl;
}

void Warlock::introduce(void) const {
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

std::string &Warlock::getName(void) const {
	return const_cast<std::string &>(this->name);
}

std::string &Warlock::getTitle(void) const {
	return const_cast<std::string &>(this->title);
}

void Warlock::setTitle(const std::string &title) {
	this->title = title;
}


void Warlock::learnSpell(const ASpell *spell) {
	this->_spells.push_back(spell->clone());
	delete spell;
}

void Warlock::forgetSpell(const std::string &spellName) {
	std::vector<ASpell *>::iterator it = this->_spells.begin();
	std::vector<ASpell *>::iterator ite = this->_spells.end();
	for (; it != ite; ++it) {
		if ((*it)->getName() == spellName)
		{
			this->_spells.erase(it);
			delete *it;
			return;
		}
	}
}

void Warlock::launchSpell(const std::string &spellName, const ATarget &target) const {
	std::vector<ASpell *>::const_iterator it = this->_spells.begin();
	std::vector<ASpell *>::const_iterator ite = this->_spells.end();
	for (; it != ite; ++it) {
		if ((*it)->getName() == spellName)
		{
			(*it)->launch(target);
			return;
		}
	}
}
