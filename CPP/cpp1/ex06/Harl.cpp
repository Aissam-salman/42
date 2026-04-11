/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:39:20 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/11 18:18:00 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <functional>
#include <iostream>
#include <string>

Harl::Harl() {};
Harl::~Harl() {};

void Harl::_debug(void) { std::cout << "[DEBUG]: I love having extra bacon.\n"; }

void Harl::_info(void) {
  std::cout << "[INFO]: I cannot believe adding extra bacon costs more money.\n";
}

void Harl::_warning(void) {
  std::cout
      << "[WARNING]: I think I deserve to have some extra bacon for free.\n";
}

void Harl::_error(void) {
  std::cout
      << "[ERROR]: This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level) {
  int levelIndex;
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  void (Harl::*log[4])(void) = {
      &Harl::_debug,
      &Harl::_info,
      &Harl::_warning,
      &Harl::_error,
  };

  levelIndex = 0;
	int i = 0;
  while (levelIndex < 4) {
    if (level == levels[i]) {
      levelIndex = i;
			break;
    }
		i++;
  }
  switch (levelIndex) {
  case 0:
    (this->*log[0])();
    // fallthrough
  case 1:
    (this->*log[1])();
    // fallthrough
  case 2:
    (this->*log[2])();
    // fallthrough
  case 3:
    (this->*log[3])();
    break;
  default:
    std::cerr
        << "Error: level not found <LEVEL> = DEBUG, INFO, WARNING or ERROR"
        << std::endl;
  }
}
