/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:32:17 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/12 11:15:15 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <algorithm>

// Constructors , Copy Constructor, Destructor
BitcoinExchange::BitcoinExchange(std::string dBFileName_val)
    : _dBFileName(dBFileName_val){};

BitcoinExchange::BitcoinExchange(BitcoinExchange const &source)
    : _dBFileName(source._dBFileName) {
  *this = source;
};

BitcoinExchange::~BitcoinExchange(void){};

// Overloaded Operators
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

void BitcoinExchange::dBImport() {
  std::ifstream dBFile(_dBFileName.c_str());

  if (dBFile.is_open() != true) {
    throw DBImportException();
  }

  // std::cout << "reading in " << _dBFileName << std::endl;

  std::string line;
  std::string date;
  std::string value_str;
  double value;
  char *end = 0;

  while (std::getline(dBFile, line)) {
    date = line.substr(0, 10);
    value_str = line.substr(11);
    value = std::strtod(value_str.c_str(), &end);
    _map.insert(std::make_pair(date, value));
  }

  if (_map.find("date,excha") != _map.end())
    _map.erase("date,excha");

  dBFile.close();
};

double BitcoinExchange::valueLookup(std::string lookup) {
  // O(log n) time complexity
  std::map<std::string, double>::iterator it = _map.lower_bound(lookup);
  // If iterator at beginning but not equal to begin string, error
  if (it == _map.begin() && it->first != lookup)
    throw DateTooEarlyException();
  // Get the closest lower date if not exact match
  if (it->first != lookup)
    it--;
  return it->second;
};

// Exception Classes
BitcoinExchange::DBImportException::DBImportException(){};
BitcoinExchange::DBImportException::~DBImportException() throw(){};
const char *BitcoinExchange::DBImportException::what() const throw() {
  return ("Error: could not import database csv file.");
}

BitcoinExchange::DateTooEarlyException::DateTooEarlyException(){};
BitcoinExchange::DateTooEarlyException::~DateTooEarlyException() throw(){};
const char *BitcoinExchange::DateTooEarlyException::what() const throw() {
  return ("Error: date selected is before any recorded prices.");
}
