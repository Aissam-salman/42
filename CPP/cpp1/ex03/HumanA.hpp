/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:34:20 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/10 15:49:06 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
public:
	HumanA(std::string name, Weapon &wp);
	~HumanA();

	void attack(void);

private:
	Weapon &_weapon;
	std::string _name;
};


#endif
