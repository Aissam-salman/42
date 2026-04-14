/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:27:06 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/07 11:27:07 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string Contact::getNumber(void) const { return this->_number; }
std::string Contact::getFirstname(void) const { return this->_firstname; }
std::string Contact::getLastname(void) const { return this->_lastname; }
std::string Contact::getNickname(void) const { return this->_nickname; }
int Contact::getIndex(void) const { return this->_index; }

static int ft_is_digit_only(std::string nb) {
  for (size_t i = 0; i < nb.length(); i++) {
    if (!std::isdigit(nb[i]))
      return (1);
  }
  return (0);
}

static int ft_is_alpha_only(std::string str) {
  for (size_t i = 0; i < str.length(); i++) {
    if (!std::isalpha(str[i]))
      return (1);
  }
  return (0);
}

int Contact::setNumber(std::string newNumber) {
  if (newNumber.length() != 10 || ft_is_digit_only(newNumber)) {
    std::cout << "Invalid number!\n";
    return (0);
  }
  this->_number = newNumber;
  return (1);
}

int Contact::setFirstname(std::string newFirstname) {
  if (newFirstname.empty() || ft_is_alpha_only(newFirstname)) {
    std::cout << "Empty or not alpha not allowed!\n";
    return (0);
  }
  this->_firstname = newFirstname;
  return (1);
}

int Contact::setLastname(std::string newLastname) {
  if (newLastname.empty() || ft_is_alpha_only(newLastname)) {
    std::cout << "Empty or not alpha not allowed!\n";
    return (0);
  }
  this->_lastname = newLastname;
  return (1);
}

int Contact::setNickname(std::string newNickname) {
  if (newNickname.empty() || ft_is_alpha_only(newNickname)) {
    std::cout << "Empty or not alpha not allowed!\n";
    return (0);
  }
  this->_nickname = newNickname;
  return (1);
}

int Contact::setIndex(int newIndex) {
  if (newIndex >= 0 && newIndex <= 8) {
    this->_index = newIndex;
    return (1);
  }
  return (0);
}

void Contact::create(void) {
  std::string fn;
  std::string ln;
  std::string nn;
  std::string nb;

  int count = 0;
  while (count != 1) {
    std::cout << "Firstname: ";
    std::cin >> fn;
		if (std::cin.fail())
			return;
    count += this->setFirstname(fn);
  }
  while (count != 2) {
    std::cout << "Lastname: ";
    std::cin >> ln;
		if (std::cin.fail())
			return;
    count += this->setLastname(ln);
  }
  while (count != 3) {
    std::cout << "Nickname: ";
    std::cin >> nn;
		if (std::cin.fail())
			return;
    count += this->setNickname(nn);
  }
  while (count != 4) {
    std::cout << "Numero: ";
    std::cin >> nb;
		if (std::cin.fail())
			return;
    count += this->setNumber(nb);
  }
}

void Contact::generate(std::string fn, std::string ln, std::string nn,
                       std::string nb) {
  this->setFirstname(fn);
  this->setLastname(ln);
  this->setNickname(nn);
  this->setNumber(nb);
}
