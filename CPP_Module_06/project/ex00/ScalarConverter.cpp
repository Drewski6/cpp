/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:09:14 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/15 19:25:16 by dpentlan         ###   ########.fr       */
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

  // float test

  {
    if (inputStr.at(inputStr.length() - 1) == 'f') {
      std::cout << "possible float" << std::endl;
      std::string set = "0123456789.-f";
      if (inputStr.find_first_not_of(set) != std::string::npos) {
        std::cout << "found char not in set" << std::endl;
        return ERROR;
      }
      std::stringstream ss_f_num;
      ss_f_num << atof(inputStr.c_str());

      if (inputStr.substr(0, inputStr.length() - 2) == ss_f_num.str())
        std::cout << "inputStr and ss_f_num are equal!" << std::endl;
      std::cout << ss_f_num.str() << std::endl;
      // std::cout << f_num << std::endl;
    }
  }
  // Stopping for now. The problem I'm having is that I cant figure out a way to
  // determin if a number is float, double or error. And I think the main reason
  // for this is because I havent figured exactly what should be considered an
  // error and what should not based on the subject. It's a little ambiguous and
  // I'm thinking I need to be strict, but that would make the functions long,
  // compicated and not elegant. So, I'll come back later.

  // {
  //   if (inputStr.find(".") != std::string::npos &&
  //       inputStr.find(".") == inputStr.rfind(".")) {
  //     std::string set = "0123456789.f-";
  //     if (inputStr.find_first_not_of(set) != std::string::npos) {
  //       std::cout << "found char not in set" << std::endl;
  //       return ERROR;
  //     }
  //     if (inputStr.find("f") != std::string::npos) {
  //       if (inputStr.at(inputStr.length() - 1) == 'f' &&
  //           inputStr.find("f") == inputStr.rfind("f")) {
  //         return FLOAT;
  //       } else {
  //         std::cout << "f but not only one" << std::endl;
  //         return ERROR;
  //       }
  //     } else {
  //       return DOUBLE;
  //     }
  //   }
  // }

  // double test

  {}

  std::cout << "end of func" << std::endl;
  return ERROR;
}
