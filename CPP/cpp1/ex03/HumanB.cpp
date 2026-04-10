/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:44:22 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/10 15:48:32 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name): _name(name) {
}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon wp)
{
	this->_weapon = wp;
}

void HumanB::attack(void){
	std::cout << this->_name <<  " attacks with their " << this->_weapon.getType() << std::endl;
}
