/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:59:15 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/28 12:54:45 by alamjada         ###   ########.fr       */
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
    btc.openD(av[1]);
  } catch (BitcoinExchange::ErrorOpenFileException &eo) {
    std::cout << eo.what() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  // try open av[1]
  // not "Error: could not open file."
  // read data.csv
  // stock line   key date, value exchange_rate dans map
  // read av[i]
  // stock line key date, value value dans une map
  // check data , value [0, 1000]
  //   print error
  // search date in data , or lower date (closest)
  // compute exchange_rate * value
  // print YYYY-MM-DD => value = compute
  // handle error

  return 0;
}

// const std::string _dataPath;
// std::map<std::string, float> _data;
// std::map<std::string, float> _file;
// std::map<std::string, std::string> _out;

// bool isOpen(char *filename) const;
// void storeData(std::string const &data);
// void storeFile(ofstream &oFile);
// void checkLine(std::string const &line);
// float find(std::string const date);
// int find(std::string const date);
// void print();
//  NotPositiveNumberException
//  BadInputException
//  ToLargeNumberException
//  ErrorOpenFileException
