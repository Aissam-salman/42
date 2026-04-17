/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:02:16 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/17 21:21:50 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <string>

class Dog : public Animal {
public:
  Dog(void);
  Dog(Dog const &src);
  Dog &operator=(Dog const &rhs);
  virtual ~Dog();

  virtual void makeSound(void) const;

};

#endif
