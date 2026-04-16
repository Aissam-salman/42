/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:46:45 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/16 15:51:20 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap &src);
  ~ScavTrap();
  ScavTrap &operator=(const ScavTrap &rhs);

  void attack(std::string const &target);
  void guardGate(void);
};

#endif
