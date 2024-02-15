/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:14:52 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/15 11:57:42 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.hpp"

// Constructors , Copy Constructor, Destructor
Fixed::Fixed(void)
    : _fixedNum(0){
          // std::cout << "Default constructor called" << std::endl;
      };

Fixed::Fixed(const int num)
    // Simple bitshift to move bin point to the left _binPnt amount of times.
    // int | binary
    //   3 | 00000000000000000000000000000010. | _binPnt of 0
    //   3 | 000000000000000000000010.00000000 | _binPnt of 8
    : _fixedNum(num << _binPnt){
          // std::cout << "Int constructor called" << std::endl;
      };

Fixed::Fixed(const float fNum)
    // Input Float (*TIMES*) 2 to the _binPntth power (=EQUALS=) our _fixedNum
    // Use roundf to round to nearest integer (more accurate than cast).
    : _fixedNum(static_cast<float>(roundf(fNum * (1 << _binPnt)))){
          // std::cout << "Float constructor called" << std::endl;
      };

Fixed::Fixed(Fixed const &source) {
  // std::cout << "Copy constructor called" << std::endl;
  *this = source;
}

Fixed::~Fixed(void){
    // std::cout << "Destructor Called" << std::endl;
};

// Assignment Operator
Fixed &Fixed::operator=(Fixed const &rhs) {
  // std::cout << "Copy assignment operator called" << std::endl;
  if (this == &rhs)
    return (*this);
  this->_fixedNum = rhs.getRawBits();
  return (*this);
};

// Comparison Operators
bool Fixed::operator<(Fixed const &rhs) const {
  return (_fixedNum < rhs._fixedNum);
};

bool Fixed::operator>(Fixed const &rhs) const {
  return (_fixedNum > rhs._fixedNum);
};

bool Fixed::operator<=(Fixed const &rhs) const {
  return (_fixedNum <= rhs._fixedNum);
};

bool Fixed::operator>=(Fixed const &rhs) const {
  return (_fixedNum >= rhs._fixedNum);
};

bool Fixed::operator==(Fixed const &rhs) const {
  return (_fixedNum == rhs._fixedNum);
};

bool Fixed::operator!=(Fixed const &rhs) const {
  return (_fixedNum != rhs._fixedNum);
};

// Arrithmetic Operators
Fixed Fixed::operator+(Fixed const &rhs) {
  return Fixed(this->toFloat() + rhs.toFloat());
};

Fixed Fixed::operator-(Fixed const &rhs) {
  return Fixed(this->toFloat() - rhs.toFloat());
};

Fixed Fixed::operator*(Fixed const &rhs) {
  return Fixed(this->toFloat() * rhs.toFloat());
};

Fixed Fixed::operator/(Fixed const &rhs) {
  return Fixed(this->toFloat() / rhs.toFloat());
};
// Increment/Decrement Operators
Fixed &Fixed::operator++(void) {
  ++_fixedNum;
  return *this;
};

Fixed &Fixed::operator--(void) {
  --_fixedNum;
  return *this;
};

Fixed Fixed::operator++(int) {
  Fixed temp(*this);
  ++(*this);
  return (temp);
};

Fixed Fixed::operator--(int) {
  Fixed temp(*this);
  --(*this);
  return (temp);
};

// Static Functions
Fixed &Fixed::min(Fixed &first, Fixed &second) {
  if (first.getRawBits() > second.getRawBits())
    return second;
  else
    return first;
};

Fixed &Fixed::max(Fixed &first, Fixed &second) {
  if (first.getRawBits() > second.getRawBits())
    return first;
  else
    return second;
};

const Fixed &Fixed::min(const Fixed &first, const Fixed &second) {
  if (first.getRawBits() > second.getRawBits())
    return second;
  else
    return first;
};

const Fixed &Fixed::max(const Fixed &first, const Fixed &second) {
  if (first.getRawBits() > second.getRawBits())
    return first;
  else
    return second;
};

// Stream Insertion Operator
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
  // Our Fixed Point Num (/DIVIDED/) 2 ^ _binPnt (=EQUALS=) return to float.
  return (static_cast<float>(_fixedNum) / (1 << _binPnt));
};

int Fixed::toInt(void) const {
  // Bit shift in other direction to return to regular int.
  return (_fixedNum >> _binPnt);
};
