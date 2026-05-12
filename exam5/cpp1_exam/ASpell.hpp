
#pragma once
#include <string>
#include "ATarget.hpp"


class ASpell {
	protected:
		std::string name;
		std::string effects;

	public:
		ASpell(void);
		ASpell(std::string name, std::string effects);

		ASpell(const ASpell &src);
		ASpell &operator=(const ASpell &rhs);

		virtual ~ASpell(void);

		virtual ASpell *clone() const = 0;
		std::string &getName(void) const;
		std::string &getEffects(void) const;
		void launch(const ATarget &target) const;
};
