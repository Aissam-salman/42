/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:54:17 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 11:06:19 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public AAnimal {
public:
  Cat(void);
  Cat(Cat const &src);
  Cat &operator=(Cat const &rhs);
  virtual ~Cat(void);

  virtual void makeSound(void) const;

private:
  Brain *_brain;
};

#endif
