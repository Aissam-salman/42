/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:24:58 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/28 12:05:13 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <ios>
#include <iostream>

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

void BitcoinExchange::openD(std::string filename) const {
  std::ifstream ifs;

  ifs.open(filename.c_str(), std::ios_base::in);
  if (!ifs.is_open()) {
    throw BitcoinExchange::ErrorOpenFileException();
  }
  std::string line;
  while (std::getline(ifs, line, '\n')) {
    std::cout << line << std::endl;
  }
  ifs.close();
}
