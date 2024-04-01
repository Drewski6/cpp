/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:09:14 by dpentlan          #+#    #+#             */
/*   Updated: 2024/04/01 16:34:49 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Yes I put everything in one large function....

void ScalarConverter::convert(std::string str) {

  // Easy stuff first
  if (str == "nan" || str == "nanf") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
    return;
  } else if (str == "+inf" || str == "+inff") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
    return;
  } else if (str == "-inf" || str == "-inff") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
    return;
  }

  // If input is char
  if (str.size() == 1) {
    char c = *str.c_str();
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
    return;
  }

  // set precision for float and double printing
  int precision = 1;
  size_t decimalPos = str.find('.');
  if (decimalPos != std::string::npos) {
    precision = str.length() - decimalPos - 1;
  }
  if (str.find('f') != std::string::npos)
    precision--;

  std::cout << "precision: " << precision << std::endl;
  std::cout << std::fixed << std::setprecision(precision);

  // convert string to double, then cast to other types.
  char *end = 0;
  double d_num = std::strtod(str.c_str(), &end);

  // errno set to ERANGE if overflow/underflow occurs. strtod err.
  if (errno == ERANGE) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return;
  }

  if (*end == '\0' || *end == 'f') {

    // Char
    if (d_num > CHAR_MAX || d_num < CHAR_MIN)
      std::cout << "char: impossible " << std::endl;
    else if (d_num > 126 || d_num < 32)
      std::cout << "char: Non displayable" << std::endl;
    else
      std::cout << "char: '" << static_cast<char>(d_num) << "'" << std::endl;

    // Int
    if (d_num > INT_MAX || d_num < INT_MIN) {
      std::cout << "int: impossible" << std::endl;
    } else {
      std::cout << "int: " << static_cast<int>(d_num) << std::endl;
    }

    // Float
    if (d_num > FLT_MAX || d_num < -FLT_MAX) {
      std::cout << "float: impossible" << std::endl;
    } else {
      std::cout << "float: " << static_cast<float>(d_num) << "f" << std::endl;
    }

    // Double
    std::cout << "double: " << d_num << std::endl;

    return;
  }

  // If nothing has printed up to this point. Catch all condition.
  std::cout << "DEBUG: CATCH ALL" << std::endl;
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
  return;
};
