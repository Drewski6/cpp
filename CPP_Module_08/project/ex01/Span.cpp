/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:35:17 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/29 14:41:55 by dpentlan         ###   ########.fr       */
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
  if (_nums.size() < _maxVecSize)
    _nums.push_back(num);
  else
    throw OutOfSpaceException();
  return;
};

int Span::shortestSpan() {
  int shortest = 2147483647;    // start at max_int.
  std::set<int> _numsSet;       // create empty set
  if (_nums.size() <= 1)        // check size is at least 2
    throw NotEnoughElementsException();

  // copy vector into set (this sorts and eliminates duplicates)
  std::copy(_nums.begin(), _nums.end(), std::inserter(_numsSet, _numsSet.end()));
  // use adjacent_find to compare elements with ShortestSpanPredicate functor.
  std::adjacent_find(_numsSet.begin(), _numsSet.end(), 
                     ShortestSpanPredicate(shortest));
  // ShortestSpanPredicate functor edits shortest by ref and finds the shortest
  // span in the set.
  return (shortest);
};

int Span::longestSpan() {
  // longestSpan using min_element and max_element algorithms.
  if (_nums.size() <= 1)
    throw NotEnoughElementsException();
  std::vector<int>::iterator min = std::min_element(_nums.begin(), _nums.end());
  std::vector<int>::iterator max = std::max_element(_nums.begin(), _nums.end());
  return ((*max) - (*min));
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

// ShortestSpanPredicate Functor Constructor and operator()
Span::ShortestSpanPredicate::ShortestSpanPredicate(int& shortest) : _shortest(shortest) {};

bool Span::ShortestSpanPredicate::operator()(int a, int b) const {
  int diff = std::abs(a - b);
  if (diff < _shortest)
    _shortest = diff;
  return (0);
}
