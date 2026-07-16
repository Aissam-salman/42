/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:59:15 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/28 19:51:18 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Error: need file in param" << std::endl;
    return 1;
  }
  BitcoinExchange btc = BitcoinExchange("data.csv");

  try {
    btc.openAndStore(av[1]);
		btc.exchange();
  } catch (BitcoinExchange::ErrorOpenFileException &eo) {
    std::cout << eo.what() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
