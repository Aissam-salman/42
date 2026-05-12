#pragma once

#include <string>

class ASpell;


class ATarget {
	protected:
		std::string type;

	public:
		ATarget(void);
		ATarget(std::string type);

		ATarget(const ATarget &src);
		ATarget &operator=(const ATarget &rhs);

		virtual ~ATarget(void);

		virtual ATarget *clone() const = 0;
		std::string &getType(void) const;

		void getHitBySpell(const ASpell &spell) const;
};
