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
  int input;

  input = 0;
  while (input != 3) {
    phone.start();
    std::cin >> input;
    std::cout << "\n";
    switch (input) {
    case 1:
      phone.search();
      break;
    case 2:
      phone.add();
      break;
    case 3:
      phone.exit();
      break;
    case 4:
      phone.generate();
      break;
    default:
      std::cout << "1, 2 or 3 only!\n";
    }
  }
  return (0);
}
