/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 21:40:26 by alamjada          #+#    #+#             */
/*   Updated: 2026/06/23 12:04:21 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class AAnimal {
public:
  AAnimal(void);
  AAnimal(AAnimal const &src);
  AAnimal &operator=(AAnimal const &rhs);
  virtual ~AAnimal(void) = 0;

  virtual void makeSound(void) const;
  std::string getType(void) const;

protected:
  std::string _type;
};

#endif
