/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:09:14 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/06 16:38:03 by dpentlan         ###   ########.fr       */
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

  // If input is char (excluding digits because subject wants 0 as an int)
  if (str.size() == 1 && (*str.c_str() < '0' || *str.c_str() > '9')) {
    char c = *str.c_str();
    if (c > 126 || c < 32)
      std::cout << "char: Non displayable" << std::endl;
    else
      std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    return;
  }

  // Quick error check for number of f's
  int num_fs = 0;
  for (int i = 0; str[i]; i++) {
    if (str[i] == 'f')
      num_fs++;
    if (num_fs > 1) {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: impossible" << std::endl;
      std::cout << "double: impossible" << std::endl;
      return;
    }
  }

  // set precision for float and double printing
  int precision = 1;
  size_t decimalPos = str.find('.');
  if (decimalPos != std::string::npos) {
    precision = str.length() - decimalPos - 1;
  }
  if (str.find('f') != std::string::npos)
    precision--;
  if (precision == 0)
    precision = 1;

  // std::cout << "precision: " << precision << std::endl;
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
  // std::cout << "DEBUG: CATCH ALL" << std::endl;
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
  return;
};
