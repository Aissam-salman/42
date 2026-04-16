/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:51:30 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/16 18:07:14 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
public:
  DiamondTrap(std::string name);
  ~DiamondTrap(void);
  DiamondTrap(DiamondTrap const &src);
  DiamondTrap &operator=(DiamondTrap const &rhs);

  void attack(std::string const &target);

private:
  std::string _name;
};

#endif
