/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:16:40 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/15 18:13:17 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
public:
	ClapTrap(std::string name);
  ClapTrap(ClapTrap const &src);
  ClapTrap &operator=(ClapTrap const &rhs);
  virtual ~ClapTrap();

	virtual void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName(void) const;
	int getHitPoints(void) const;
	int getEnergyPoints(void) const;
	int getAttackDamage(void) const;

	void setName(std::string name);
	void setHitPoints(int hit);
	void setEnergyPoints(int energy);
	void setAttackDamage(int damage);

private:
  std::string _name;
  int _hitPoints;
  int _energyPoints;
  int _attackDamage;
};

#endif
