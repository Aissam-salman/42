/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:37:04 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/11 17:54:32 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av) {
  Harl harl;

  if (ac != 2) {
    std::cerr << "./harl <LEVEL>" << std::endl;
    std::cout << "DEBUG, INFO, WARNING or ERROR" << std::endl;
    return (1);
  }
  if (!av[1]) {
    std::cerr << "Error: empty <LEVEL> = DEBUG, INFO, WARNING or ERROR"
              << std::endl;
    return (1);
  }
  harl.complain(av[1]);
  return (0);
}
