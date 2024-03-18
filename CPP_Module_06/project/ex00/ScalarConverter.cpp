/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:09:14 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/15 21:25:23 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
    std::cout << "INF" << std::endl;
    break;
  case (5):
    std::cout << "NAN" << std::endl;
    break;
  default:
    std::cout << "ERROR" << std::endl;
    break;
  }
};

e_type ScalarConverter::_detectType(std::string inputStr) {

  // inf test

  if (inputStr == "-inff" || inputStr == "+inff" || inputStr == "-inf" ||
      inputStr == "+inf")
    return INF;

  // nan test

  if (inputStr == "nan" || inputStr == "nanf")
    return NAN;

  // char test

  if (inputStr.length() == 1 && std::isdigit(inputStr.at(0)) != true)
    return CHAR;

  // int test

  {
    std::stringstream ss_number;

    ss_number << atoi(inputStr.c_str());

    if (inputStr == ss_number.str()) {
      return INT;
    }
  }

  // float/double test

  {
    if (inputStr.find(".") != std::string::npos &&
        inputStr.find(".") == inputStr.rfind(".")) {
      std::string set = "0123456789.f-";
      if (inputStr.find_first_not_of(set) != std::string::npos) {
        return ERROR;
      }
      int neg_log = inputStr.find("-");
      if (neg_loc != std::string::npos) {
        return ERROR;
      }
      if (inputStr.find("f") != std::string::npos) {
        if (inputStr.at(inputStr.length() - 1) == 'f' &&
            inputStr.find("f") == inputStr.rfind("f")) {
          return FLOAT;
        } else {
          return ERROR;
        }
      } else {
        return DOUBLE;
      }
    }
  }

  return ERROR;
}
