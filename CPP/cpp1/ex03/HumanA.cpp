/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:37:32 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/10 15:49:23 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &wp) : _weapon(wp), _name(name) {}

HumanA::~HumanA() {}

void HumanA::attack(void) {
  std::cout << this->_name << " attacks with their " << this->_weapon.getType()
            << std::endl;
}
