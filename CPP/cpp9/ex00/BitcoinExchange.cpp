/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:24:58 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/28 13:33:04 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const std::string dataPath)
    : _dataPath(dataPath) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
    : _dataPath(src._dataPath) {
  this->_data = std::map<std::string, float>(src._data);
  this->_file = std::map<std::string, float>(src._file);
  this->_out = std::map<std::string, std::string>(src._out);
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
  if (this != &rhs) {
    this->_data.clear();
    this->_file.clear();
    this->_out.clear();
    this->_data = std::map<std::string, float>(rhs._data);
    this->_file = std::map<std::string, float>(rhs._file);
    this->_out = std::map<std::string, std::string>(rhs._out);
  }
  return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {
  this->_data.clear();
  this->_file.clear();
  this->_out.clear();
}

void BitcoinExchange::openAndStore(std::string filename) {
  std::ifstream ifs;

  ifs.open(filename.c_str(), std::ios_base::in);
  if (!ifs.is_open())
    throw BitcoinExchange::ErrorOpenFileException();

  std::string line;
  int lineNb = 0;

  while (std::getline(ifs, line, '\n')) {
    lineNb++;
    if (lineNb == 1 && line.find("date") != std::string::npos &&
        line.find("|") != std::string::npos &&
        line.find("value") != std::string::npos) {
      std::cout << "firstline: " << line << std::endl;
      continue;
    }

    std::stringstream ss(line);
    std::string item;

    std::string data;
    float value = 0;
    int row = 0;

    while (std::getline(ss, item, ' ')) {
      if (item.compare("|") == 0)
        continue;
      if (row == 0) {
        data = item;
        std::cout << "data: " << data << ", ";
        row++;
      } else {
        value = strtof(item.c_str(), NULL);
        row = 0;
        std::cout << std::fixed << std::setprecision(2) << "value: " << value
                  << std::endl;
      }
    }
    if (value == 0)
      std::cout << std::endl;

    (void)value;
  }
  ifs.close();
}
