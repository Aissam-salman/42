/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:54:17 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/17 21:30:26 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>

class Cat : public Animal {
	public:
		Cat(void);
		Cat(Cat const &src);
		Cat &operator=(Cat const &rhs);
		virtual ~Cat(void);

		virtual void makeSound(void) const;
};

#endif
