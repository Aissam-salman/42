/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:57:40 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 17:09:35 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Cure : public AMateria {
private:
  std::string _name;

public:
  Cure(void);
  Cure(std::string const name);
  Cure(const Cure &src);
  Cure &operator=(const Cure &rhs);
  ~Cure(void);

  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};

#endif
