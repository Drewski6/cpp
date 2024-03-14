/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:09:14 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/14 18:06:34 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

// Constructors , Copy Constructor, Destructor
ScalarConverter::ScalarConverter(void){};
ScalarConverter::ScalarConverter(ScalarConverter const &source) {
  *this = source;
};
ScalarConverter::~ScalarConverter(void){};

// Overloaded Operators
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
  if (this == &rhs)
    return (*this);
  return (*this);
};

void ScalarConverter::convert(std::string inputStr) {
  e_type inputType;

  inputType = _detectType(inputStr);

  switch (inputType) {
  case (0):
    std::cout << "CHAR" << std::endl;
    break;
  case (1):
    std::cout << "INT" << std::endl;
    break;
  case (2):
    std::cout << "FLOAT" << std::endl;
    break;
  case (3):
    std::cout << "DOUBLE" << std::endl;
    break;
  case (4):
    std::cout << "NONE" << std::endl;
    break;
  default:
    std::cout << "DEFAULT" << std::endl;
    break;
  }
};

e_type ScalarConverter::_detectType(std::string inputStr) {

  // char test

  {
    if (inputStr.length() == 1 &&
        ((inputStr.c_str()[0] >= 0 && inputStr.c_str()[0] <= 47) ||
         (inputStr.c_str()[0] >= 58))) {
      return CHAR;
    }
  }

  // int test

  {
    int int_number;

    int_number = atoi(inputStr.c_str());

    std::stringstream int_ss_number;
    int_ss_number << int_number;

    if (inputStr == int_ss_number.str()) {
      return INT;
    }
  }

  // float test

  {
    double f_number;

    f_number = atof(inputStr.c_str());

    std::stringstream ss_number;
    ss_number << f_number;

    std::cout << ss_number.str() << std::endl;
    std::cout << f_number << std::endl;

    if (inputStr.substr(0, inputStr.length() - 1) == ss_number.str() &&
        inputStr.at(inputStr.length() - 1) == 'f') {
      return FLOAT;
    }
  }

  // double test

  {
    double d_number;

    d_number = atof(inputStr.c_str());

    std::stringstream ss_number;
    ss_number << d_number;

    if (inputStr == ss_number.str()) {
      return DOUBLE;
    }
  }

  return NONE;
}
