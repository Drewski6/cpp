/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:32:17 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/21 19:21:31 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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
  return (*this);
};

void BitcoinExchange::dBImport() {
  std::ifstream dBFile(_dBFileName.c_str());
  // check if file is open
  if (dBFile.is_open() != true) {
    throw DBImportException();
  }
  // init variables
  std::string line;
  std::string date;
  std::string value_str;
  double value;
  char *end = 0;
  // Read file and insert into map
  while (std::getline(dBFile, line)) {
    date = line.substr(0, 10);
    value_str = line.substr(11);
    value = std::strtod(value_str.c_str(), &end);
    if (errno == ERANGE)
      throw ValueTooLargeException();
    _map.insert(std::make_pair(date, value));
  }
  // Remove the header
  if (_map.find("date,excha") != _map.end())
    _map.erase("date,excha");
  // Close file
  dBFile.close();
}

std::string BitcoinExchange::evaluateOutput(std::string &inputStr) {
  std::stringstream ss;
  double value = _inputParse(inputStr);
  // format output string
  ss << inputStr.substr(0, 10) << " => " << value << " = "
     << _valueLookup(inputStr.substr(0, 10)) * value;
  return (ss.str());
};

double BitcoinExchange::_valueLookup(std::string lookup) {
  // O(log n) time complexity
  std::map<std::string, double>::iterator it = _map.lower_bound(lookup);
  if (it == _map.end()) {
    it--;
    return it->second;
  }
  // If iterator at beginning but not equal to begin string, error
  if (it == _map.begin() && it->first != lookup)
    throw DateTooEarlyException();
  // Get the closest lower date if not exact match
  if (it->first != lookup)
    it--;
  return it->second;
};

double BitcoinExchange::_inputParse(std::string inputStr) {
  std::stringstream ss;
  std::string date_str;
  std::string sep_str;
  std::string value_str;
  double value;
  char *end = 0;

  // First check size. Date size = 10, seperator size = 3, value must be at
  // least 1.
  if (inputStr.size() < 14)
    throw BadInputException(inputStr);

  // Error checking for Date
  date_str = inputStr.substr(0, 10);
  if (!_isValidDate(date_str))
    throw BadInputException(inputStr);

  // Error checking for seperator
  sep_str = inputStr.substr(10, 3);
  if (sep_str != " | ")
    throw BadInputException(inputStr);

  // Error checking for Value
  value_str = inputStr.substr(13);
  value = std::strtod(value_str.c_str(), &end);
  if (errno == ERANGE)
    throw ValueTooLargeException();
  if (value < 0)
    throw ValueNotPositiveException();
  if (value > 1000)
    throw ValueTooLargeException();
  ss << value;
  if (ss.str() != value_str)
    throw BadInputException(inputStr);

  return (value);
};

bool BitcoinExchange::_isValidDate(std::string dateStr) {
  // Check length of the string
  if (dateStr.length() != 10)
    return false;
  // Check dashes are used to separate year, month, and day
  if (dateStr[4] != '-' || dateStr[7] != '-')
    return false;
  // Check that only digits are used for year, month, and day
  for (int i = 0; i < 10; ++i) {
    if (i == 4 || i == 7)
      continue;
    if (!isdigit(dateStr[i]))
      return false;
  }
  // use istringstream to extract year, month, and day
  std::istringstream iss(dateStr);
  int year, month, day;
  char dash;
  iss >> year >> dash >> month >> dash >> day;
  // Check ranges of year, month, and day
  if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
    return false;
  // Check april, june, september, november have 30 days
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    return false;
  // check February has 28 or 29 days
  if (month == 2) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
      if (day > 29)
        return false;
    } else {
      if (day > 28)
        return false;
    }
  }

  return true;
}

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

BitcoinExchange::BadInputException::BadInputException(std::string str_val)
    : _str() {
  _str = "Error: bad input => " + str_val;
};
BitcoinExchange::BadInputException::~BadInputException() throw(){};
const char *BitcoinExchange::BadInputException::what() const throw() {
  return (_str.c_str());
}

BitcoinExchange::ValueTooLargeException::ValueTooLargeException(){};
BitcoinExchange::ValueTooLargeException::~ValueTooLargeException() throw(){};
const char *BitcoinExchange::ValueTooLargeException::what() const throw() {
  return ("Error: too large a number.");
}

BitcoinExchange::ValueNotPositiveException::ValueNotPositiveException(){};
BitcoinExchange::ValueNotPositiveException::
    ~ValueNotPositiveException() throw(){};
const char *BitcoinExchange::ValueNotPositiveException::what() const throw() {
  return ("Error: not a positive number.");
}
