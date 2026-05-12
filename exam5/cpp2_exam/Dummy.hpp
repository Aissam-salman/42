#pragma once
#include "ATarget.hpp"
#include <string>

class Dummy : public ATarget {
	protected:
		Dummy(std::string type);

	public:
		Dummy(void);
		Dummy(const Dummy &src);
		Dummy &operator=(const Dummy &rhs);

		virtual ~Dummy(void);
		virtual Dummy *clone(void) const;
};
