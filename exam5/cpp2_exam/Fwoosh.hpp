#pragma once
#include "ASpell.hpp"
#include <string>

class Fwoosh : public ASpell {
	protected:
		Fwoosh(std::string name, std::string effects);

	public:
		Fwoosh(void);

		Fwoosh(const Fwoosh &src);
		Fwoosh &operator=(const Fwoosh &rhs);

		virtual ~Fwoosh(void);

		virtual Fwoosh *clone(void) const;

};
