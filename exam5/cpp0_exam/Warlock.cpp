/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 13:18:21 by alamjada          #+#    #+#             */
/*   Updated: 2026/05/11 14:35:54 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"
#include <string>
#include <iostream>

Warlock::Warlock(void): name(""), title("") {}
Warlock::Warlock(const Warlock &src) { *this = src;}
Warlock &Warlock::operator=(const Warlock &rhs) { 
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->title = rhs.title;
	}
	return *this;
}

Warlock::~Warlock(void){
	std::cout << this->name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(std::string name, std::string title): name(name), title(title) {
	std::cout << name << ": This looks like another boring day." << std::endl;
}

void Warlock::introduce(void) const {
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

std::string &Warlock::getName(void) const {
	return const_cast<std::string &>(this->name);
}

std::string &Warlock::getTitle(void) const {
	return const_cast<std::string &>(this->title);
}

void Warlock::setTitle(const std::string &title) {
	this->title = title;
}
