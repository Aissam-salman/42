/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:44:56 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/10 15:48:59 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
class HumanB {
public:
  HumanB(std::string name);
  ~HumanB();

  void attack(void);
  void setWeapon(Weapon &wp);

private:
  Weapon *_weapon;
  std::string _name;
};

#endif
