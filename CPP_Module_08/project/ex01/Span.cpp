/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:35:17 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/28 21:23:05 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors , Copy Constructor, Destructor
Span::Span(unsigned int N) : _maxVecSize(N){};
Span::Span(Span const &source) { *this = source; };
Span::~Span(void){};

// Overloaded Operators
Span &Span::operator=(Span const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods
void Span::addNumber(int num) {
  // addNumber
  if (_nums.size() < _maxVecSize)
    _nums.push_back(num);
  else
    throw OutOfSpaceException();
  return;
};

int Span::shortestSpan() {
  // shortestSpan
  return (0);
};

int Span::longestSpan() {
  // longestSpan
  return (0);
};

void Span::displaySpan() {
  std::cout << "Span Contents: [ ";
  for (std::vector<int>::iterator it = _nums.begin(); it != _nums.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << "]" << std::endl;
  std::cout << "Span Size: " << _nums.size() << std::endl;
};

// Exception Implementations
Span::OutOfSpaceException::OutOfSpaceException(){};
Span::OutOfSpaceException::~OutOfSpaceException() throw(){};
const char *Span::OutOfSpaceException::what() const throw() {
  return ("Error: Span object does not have enough room for more numbers.");
}

Span::NotEnoughElementsException::NotEnoughElementsException(){};
Span::NotEnoughElementsException::~NotEnoughElementsException() throw(){};
const char *Span::NotEnoughElementsException::what() const throw() {
  return ("Error: Cannot perform operation because Span object does not have "
          "enough numbers.");
}
