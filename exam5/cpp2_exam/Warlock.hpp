#pragma once

#include <string>
#include <vector>

class ASpell;
class ATarget;

class Warlock {
	private:
		Warlock(void);
		Warlock(const Warlock &src);
		Warlock &operator=(const Warlock &rhs);
		std::string name;
		std::string title;
		std::vector<ASpell *> _spells;

	public:
		Warlock(std::string name, std::string title);
		~Warlock(void);

		std::string &getName(void) const;
		std::string &getTitle(void) const;

		void setTitle(const std::string &title);

		void introduce(void) const;

		void learnSpell(const ASpell *spell);
		void forgetSpell(const std::string &spellName);
		void launchSpell(const std::string &spellName, const ATarget &target) const;
};
