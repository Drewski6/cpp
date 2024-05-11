/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:31:52 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/11 23:33:30 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

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
  double valueLookup(std::string lookup);

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

private:
  std::string _dBFileName;
  std::map<std::string, double> _map;
};
