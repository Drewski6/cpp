/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:14:42 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/15 10:31:44 by dpentlan         ###   ########.fr       */
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
  Fixed(const float fnum);
  Fixed(Fixed const &source);
  ~Fixed(void);

  // Assignment Operators
  Fixed &operator=(Fixed const &rhs);
  // Comparison Operators
  bool operator<(Fixed const &rhs) const;
  bool operator>(Fixed const &rhs) const;
  bool operator<=(Fixed const &rhs) const;
  bool operator>=(Fixed const &rhs) const;
  bool operator==(Fixed const &rhs) const;
  bool operator!=(Fixed const &rhs) const;
  // Arrithmetic Operators
  Fixed operator+(Fixed const &rhs);
  Fixed operator-(Fixed const &rhs);
  Fixed operator*(Fixed const &rhs);
  Fixed operator/(Fixed const &rhs);
  // Increment/Decrement Operators
  Fixed &operator++(void);
  Fixed &operator--(void);
  Fixed operator++(int);
  Fixed operator--(int);

  // Getters
  int getRawBits(void) const;
  void setRawBits(int const raw);

  // Conversion Functions
  float toFloat(void) const;
  int toInt(void) const;

  // Static Functions
  static Fixed &min(Fixed &first, Fixed &second);
  static Fixed &max(Fixed &first, Fixed &second);
  static const Fixed &min(const Fixed &first, const Fixed &second);
  static const Fixed &max(const Fixed &first, const Fixed &second);

private:
  int _fixedNum;
  static const int _binPnt = 8;
};

// Stream Insertion Operator
std::ostream &operator<<(std::ostream &os, Fixed const &f);
