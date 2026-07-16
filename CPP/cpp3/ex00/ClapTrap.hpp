/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:16:40 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/16 21:05:29 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
public:
	ClapTrap(void);
	ClapTrap(std::string name);
  ClapTrap(ClapTrap const &src);
  ClapTrap &operator=(ClapTrap const &rhs);
  ~ClapTrap();

	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName(void) const;
	int getHitPoints(void) const;
	int getEnergyPoints(void) const;
	int getAttackDamage(void) const;

private:
  std::string _name;
  int _hitPoints;
  int _energyPoints;
  int _attackDamage;
};

#endif
