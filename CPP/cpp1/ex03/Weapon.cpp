/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:30:33 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/10 15:37:16 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::~Weapon() {}

std::string Weapon::getType(void) const { return (this->_type); }

void Weapon::setType(std::string type) { this->_type = type; }
