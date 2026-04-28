/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:24:58 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/28 19:51:14 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
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
  while (std::getline(ifs, line, '\n')) {
    if (line.find("date") != std::string::npos &&
        line.find(",") != std::string::npos &&
        line.find("exchange_rate") != std::string::npos) {
      continue;
    } else if (line.empty()) {
      continue;
    }
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
  while (std::getline(ifs, line, '\n')) {
    if (line.find("date") != std::string::npos &&
        line.find("|") != std::string::npos &&
        line.find("value") != std::string::npos) {
      continue;
    } else if (line.empty()) {
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
  try {
    this->openData();
  } catch (BitcoinExchange::ErrorOpenFileException &e) {
    std::cerr << "Data source" << std::endl;
    throw BitcoinExchange::ErrorOpenFileException();
  }
}

int checkDate(std::string date) {
  struct tm tm;
  std::setlocale(LC_ALL, NULL);
  if (strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL)
    return 1;
  return 0;
}

int checkValue(float value) {
  if (value > 1000)
    return 1;
  else if (value < 0)
    return -1;
  return 0;
}

void BitcoinExchange::exchange(void) {
  std::list<Row>::iterator it = this->_file.begin();
  std::list<Row>::iterator ite = this->_file.end();
  for (; it != ite; ++it) {
    if (checkDate(it->_date) == 1) {
      std::cout << "Error: bad input => " << it->_date << std::endl;
      continue;
    }
    int cv = checkValue(it->_value);
    if (cv == -1) {
      std::cout << "Error: not a positive number." << std::endl;
      continue;
    } else if (cv == 1) {
      std::cout << "Error: too large a number." << std::endl;
      continue;
    }
    std::map<std::string, float>::iterator low =
        this->_data.lower_bound(it->_date);

    if (low->first != it->_date) {
      if (low != this->_data.begin())
        low--;
    }
    std::cout << it->_date << " => " << std::setprecision(2) << it->_value
              << " = " << (low->second * it->_value) << std::endl;
  }
}

std::ostream &operator<<(std::ostream &o, const BitcoinExchange::Row &rhs) {
  o << "Row(" << rhs._date << ", " << rhs._value << ")";
  return o;
}
