/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:10:54 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/18 16:56:25 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
private:
  std::string _name;

public:
  Ice(void);
  Ice(std::string const name);
  Ice(Ice const &src);
  Ice &operator=(Ice const &rhs);
  ~Ice(void);

  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};

#endif
