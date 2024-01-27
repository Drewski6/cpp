/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:14:52 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/26 18:57:31 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.h"

// Constructors , Copy Constructor, Destructor
Fixed::Fixed(void) {
  std::cout << "Default constructor called" << std::endl;
  _fixed_num = 0;
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
  this->_fixed_num = rhs.getRawBits();
  return (*this);
};

// Public Methods
int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (_fixed_num);
};
void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  _fixed_num = raw;
  return;
};

// Private Methods
