/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:25:01 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/17 15:28:10 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Character {
public:
	void sayHello(std::string const &target);

};

class Warrior: public Character {
public:
	void sayHello(std::string const &target);
};

class Cat {};

Character::sayHello(std::string const &target){
	std::cout << "Hello " << target << " bien ?" << std::endl;
}

Warrior::sayHello(std::string const &target){
	std::cout << "F*** " << target << ", go P ?" << std::endl;
}
