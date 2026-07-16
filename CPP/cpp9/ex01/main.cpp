/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:56:15 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/29 13:02:28 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "Error" << std::endl;
    return 1;
  }
  RPN compute = RPN(av[1]);
  compute.run();
  return 0;
}
