/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:09:14 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/15 09:08:24 by dpentlan         ###   ########.fr       */
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
    int number;

    number = atoi(inputStr.c_str());

    std::stringstream ss_number;
    ss_number << number;

    if (inputStr == ss_number.str()) {
      return INT;
    }
  }

  // float/double test

  {
    if (inputStr.find(".") != std::string::npos &&
        inputStr.find(".") == inputStr.rfind(".")) {

      std::cout << "only one . found" << std::endl;
      std::cout << "either double or float" << std::endl;

      int significant_digits = inputStr.length() - (inputStr.find(".") + 1);
      if (significant_digits > 16)
        significant_digits = 16;

      if (inputStr.at(inputStr.length() - 1) == 'f') {
        std::cout << "possible float Found!" << std::endl;
        significant_digits--;
        if (significant_digits > 7)
          significant_digits = 7;

        float number;

        number = std::atof(inputStr.c_str());

        std::cout << std::fixed << std::setprecision(significant_digits);
        std::cout << inputStr << std::endl;
        std::cout << "float number: " << number << std::endl;
        std::cout << "sizeof float: " << sizeof(float) * 8 << std::endl;
        return FLOAT;
      } else {
        double number;

        number = std::atof(inputStr.c_str());

        std::cout << std::fixed << std::setprecision(significant_digits);
        std::cout << significant_digits << std::endl;
        std::cout << inputStr << std::endl;
        std::cout << "Double number: " << number << std::endl;
        return DOUBLE;
      }
    }
  }

  return ERROR;
}
