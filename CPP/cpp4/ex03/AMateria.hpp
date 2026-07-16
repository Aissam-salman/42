/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:28:24 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 17:39:33 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
protected:
  std::string _type;

public:
  AMateria(void);
  AMateria(std::string const &type);
  AMateria(AMateria const &src);
  AMateria &operator=(AMateria const &rhs);
  virtual ~AMateria(void);

  std::string const &getType() const;
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};

#endif
