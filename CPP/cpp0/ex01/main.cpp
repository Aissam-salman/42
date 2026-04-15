/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:29:18 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/07 11:37:31 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main() {
  PhoneBook phone;
  std::string input;

  while (1) {
    phone.start();
    if (!(std::cin >> input))
			return (1);
    if (std::cin.fail() || std::cin.eof())
      return (1);
    std::cout << "\n";
    if (input == "SEARCH")
      phone.search();
    else if (input == "ADD")
      phone.add();
    else if (input == "EXIT")
      phone.exit();
    else if (input == "GENERATE")
      phone.generate();
    else
      std::cout << "SEARCH, ADD, EXIT and GENERATE only!\n";
  }
  return (0);
}
