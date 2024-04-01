/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:09:27 by dpentlan          #+#    #+#             */
/*   Updated: 2024/04/01 16:21:51 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <errno.h>
#include <float.h>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <string>

class ScalarConverter {
public:
  static void convert(std::string inputStr);

  // Need to make Constructors, Destructor, and operator= private to make
  // ScalarConverter non-instatiable like the subject asks.
private:
  ScalarConverter(void);
  ScalarConverter(ScalarConverter const &source);
  ~ScalarConverter(void);
  ScalarConverter &operator=(ScalarConverter const &rhs);
};
