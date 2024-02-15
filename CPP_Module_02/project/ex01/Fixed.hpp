/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:14:42 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/15 11:12:27 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <iostream>

class Fixed {
public:
  // Constructors , Copy Constructor, Destructor
  Fixed(void);
  Fixed(const int num);
  Fixed(const float fNum);
  Fixed(Fixed const &source);
  ~Fixed(void);

  // Overloaded Operators
  Fixed &operator=(Fixed const &rhs);

  // Getters
  int getRawBits(void) const;
  // Setters
  void setRawBits(int const raw);

  // Conversion Functions
  float toFloat(void) const;
  int toInt(void) const;

private:
  int _fixedNum;
  static const int _binPnt = 8;
};

std::ostream &operator<<(std::ostream &os, Fixed const &f);
