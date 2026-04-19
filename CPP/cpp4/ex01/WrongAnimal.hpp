/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 21:26:01 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/17 21:37:15 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
public:
  WrongAnimal(void);
  WrongAnimal(WrongAnimal const &src);
  WrongAnimal &operator=(WrongAnimal const &rhs);
  virtual ~WrongAnimal(void);

  void makeSound(void) const;
  std::string getType(void) const;

protected:
  std::string _type;
};

#endif
