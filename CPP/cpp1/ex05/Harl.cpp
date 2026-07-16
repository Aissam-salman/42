/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:39:20 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/11 18:22:57 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl() {};
Harl::~Harl() {};

void Harl::_debug(void) {
  std::cout << "[DEBUG]: I love having extra bacon.\n";
}

void Harl::_info(void) {
  std::cout
      << "[INFO]: I cannot believe adding extra bacon costs more money.\n";
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
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  void (Harl::*log[4])(void) = {
      &Harl::_debug,
      &Harl::_info,
      &Harl::_warning,
      &Harl::_error,
  };

  for (int i = 0; i < 4; i++) {
    if (level == levels[i]) {
      (this->*log[i])();
      return;
    }
  }
  std::cerr << "Error: level not found <LEVEL> = DEBUG, INFO, WARNING or ERROR"
            << std::endl;
}
