/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:09:27 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/14 16:33:27 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

enum e_type {
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
  NONE,
};

class ScalarConverter {
public:
  // Public Methods
  static void convert(std::string inputStr);

private:
  // To ensure ScalarConverter is not instanciable, we make it's constructor
  // private.
  ScalarConverter(void);
  ScalarConverter(ScalarConverter const &source);
  ~ScalarConverter(void);
  ScalarConverter &operator=(ScalarConverter const &rhs);

  // Private Methods
  static e_type _detectType(std::string inputStr);
};
