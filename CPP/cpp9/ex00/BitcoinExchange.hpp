/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:06:33 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/28 19:40:38 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <fstream>
#include <list>
#include <string>
#include <map>

class BitcoinExchange {
public:
  BitcoinExchange(const std::string dataPath);
  BitcoinExchange(const BitcoinExchange &src);
  BitcoinExchange &operator=(const BitcoinExchange &rhs);
  ~BitcoinExchange(void);

  void openAndStore(std::string filename);
	void exchange(void);

  class ErrorOpenFileException : std::exception {
  public:
    virtual const char *what() const throw() {
      return ("Error: could not open file.");
    }
  };

	class Row {
		public:
			Row(std::string date, float value): _date(date), _value(value), _err(""){}
			Row(std::string date, float value, std::string e): _date(date), _value(value), _err(e){}

			std::string _date;
			float _value;
			std::string _err;
	};

private:
  BitcoinExchange(void);
	void openData(void);
  const std::string _dataPath;
  std::map<std::string, float> _data;
  std::list<Row> _file;
  std::list<std::string> _out;
};

std::ostream &operator<<(std::ostream &o, const BitcoinExchange::Row &rhs);

#endif
