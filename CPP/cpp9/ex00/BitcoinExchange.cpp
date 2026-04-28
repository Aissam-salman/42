/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:24:58 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/28 18:03:27 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const std::string dataPath)
    : _dataPath(dataPath) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
    : _dataPath(src._dataPath) {
  this->_data = std::map<std::string, float>(src._data);
  this->_file = std::list<Row>(src._file);
  this->_out = std::list<std::string>(src._out);
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
  if (this != &rhs) {
    this->_data.clear();
    this->_file.clear();
    this->_out.clear();
    this->_data = std::map<std::string, float>(rhs._data);
    this->_file = std::list<Row>(rhs._file);
    this->_out = std::list<std::string>(rhs._out);
  }
  return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {
  this->_data.clear();
  this->_file.clear();
  this->_out.clear();
}

void BitcoinExchange::openData(void) {
  std::ifstream ifs;

  ifs.open(this->_dataPath.c_str(), std::ios_base::in);
  if (!ifs.is_open())
    throw BitcoinExchange::ErrorOpenFileException();
  std::string line;
  int lineNb = 0;
  while (std::getline(ifs, line, '\n')) {
    lineNb++;
    if (lineNb == 1 && line.find("date") != std::string::npos &&
        line.find(",") != std::string::npos &&
        line.find("exchange_rate") != std::string::npos)
      continue;
    std::stringstream ss(line);
    std::string item;
    std::string data;
    float value = 0;
    int row = 0;
    while (std::getline(ss, item, ',')) {
      if (row == 0) {
        data = item;
        row++;
      } else {
        value = strtof(item.c_str(), NULL);
        row = 0;
      }
    }
    this->_data.insert(std::make_pair(data, value));
  }
  ifs.close();
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
        row++;
      } else {
        value = strtof(item.c_str(), NULL);
        row = 0;
      }
    }
    this->_file.push_back(Row(data, value));
  }
  ifs.close();
  // std::list<Row>::iterator it = this->_file.begin();
  // std::list<Row>::iterator ite = this->_file.end();
  // for (; it != ite; ++it)
  //   std::cout << *it << std::endl;
  try {
    this->openData();
    std::map<std::string, float>::iterator it = this->_data.begin();
    std::map<std::string, float>::iterator ite = this->_data.end();

    for (; it != ite; ++it)
    	std::cout << it->first << ", " << it->second << std::endl;
  } catch (BitcoinExchange::ErrorOpenFileException &e) {
    std::cerr << "Data source" << std::endl;
    throw BitcoinExchange::ErrorOpenFileException();
  }
}

std::ostream &operator<<(std::ostream &o, const BitcoinExchange::Row &rhs) {
  o << "Row(" << rhs._date << ", " << rhs._value << ")";
  return o;
}
