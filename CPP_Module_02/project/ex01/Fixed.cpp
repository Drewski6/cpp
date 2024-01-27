/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:14:52 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/27 12:23:51 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.h"

// Constructors , Copy Constructor, Destructor
Fixed::Fixed(void) {
  std::cout << "Default constructor called" << std::endl;
  _fixedNum = 0;
};

Fixed::Fixed(const int num) {
  std::cout << "Int constructor called" << std::endl;
  // Simple bit shift to move Binary Point to the left _binPnt amount of times.
  // int | binary
  //   3 | 00000000000000000000000000000010. | _binPnt of 0
  //   3 | 000000000000000000000010.00000000 | _binPnt of 8
  _fixedNum = num << _binPnt;
};

Fixed::Fixed(const float fNum) {
  std::cout << "Float constructor called" << std::endl;
  // Input Float (*TIMES*) 2 to the _binPntth power (=EQUALS=) our Fixed Pnt Num
  _fixedNum = static_cast<int>(fNum * std::pow(2, _binPnt));
};

Fixed::Fixed(Fixed const &source) {
  std::cout << "Copy constructor called" << std::endl;
  *this = source;
}

Fixed::~Fixed(void) { std::cout << "Destructor Called" << std::endl; };

// Overloaded Operators
Fixed &Fixed::operator=(Fixed const &rhs) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this == &rhs)
    return (*this);
  this->_fixedNum = rhs.getRawBits();
  return (*this);
};

std::ostream &operator<<(std::ostream &os, Fixed const &f) {
  os << f.toFloat();
  return os;
};

// Public Methods
int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member function called" << std::endl;
  return (_fixedNum);
};
void Fixed::setRawBits(int const raw) {
  // std::cout << "setRawBits member function called" << std::endl;
  _fixedNum = raw;
  return;
};

float Fixed::toFloat(void) const {
  // Our Fixed Point Num (*TIMES*) _binPnt root of 2 (=EQUALS=) return to float.
  return (static_cast<float>(_fixedNum) * std::pow(2, -_binPnt));
};

int Fixed::toInt(void) const {
  // Bit shift in other direction to return to regular int.
  return (_fixedNum >> _binPnt);
};

// Private Methods
