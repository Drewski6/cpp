/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:31:52 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/12 19:17:53 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <cerrno>

class BitcoinExchange {
public:
  // Constructors , Copy Constructor, Destructor
  BitcoinExchange(std::string dBFileName_val);
  BitcoinExchange(BitcoinExchange const &source);
  ~BitcoinExchange(void);

  // Overloaded Operators
  BitcoinExchange &operator=(BitcoinExchange const &rhs);

  // Public Methods
  void dBImport();
  std::string evaluateOutput(std::string &inputStr);

  // Exception Classes
  class DBImportException : public std::exception {
  public:
    DBImportException();
    virtual ~DBImportException() throw();
    virtual const char *what() const throw();
  };

  class DateTooEarlyException : public std::exception {
  public:
    DateTooEarlyException();
    virtual ~DateTooEarlyException() throw();
    virtual const char *what() const throw();
  };

  class BadInputException : public std::exception {
  public:
    BadInputException(std::string str_val);
    virtual ~BadInputException() throw();
    virtual const char *what() const throw();

  private:
    std::string _str;
  };

  class ValueTooLargeException : public std::exception {
  public:
    ValueTooLargeException();
    virtual ~ValueTooLargeException() throw();
    virtual const char *what() const throw();
  };

  class ValueNotPositiveException : public std::exception {
  public:
    ValueNotPositiveException();
    virtual ~ValueNotPositiveException() throw();
    virtual const char *what() const throw();
  };

private:
  std::string _dBFileName;
  std::map<std::string, double> _map;

  double _valueLookup(std::string lookup);
  double _inputParse(std::string input);
  bool _isValidDate(std::string date);
};
