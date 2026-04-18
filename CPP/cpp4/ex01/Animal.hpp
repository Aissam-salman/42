/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:40:26 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/17 21:21:36 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
public:
  Animal(void);
  Animal(Animal const &src);
  Animal &operator=(Animal const &rhs);
  virtual ~Animal(void);

  virtual void makeSound(void) const;
	std::string getType(void) const;

protected:
  std::string _type;
};

#endif
