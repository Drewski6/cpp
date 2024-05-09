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
  if (_numsVec.size() < _maxVecSize)
    _numsVec.push_back(num);
  else
    throw OutOfSpaceException();
  return;
};

int Span::shortestSpan() {
  int shortest = 2147483647;    // start at max_int.
  std::set<int> _numsVecSet;       // create empty set
  if (_numsVec.size() <= 1)        // check size is at least 2
    throw NotEnoughElementsException();

  // copy vector into set (this sorts and eliminates duplicates)
  std::copy(_numsVec.begin(), _numsVec.end(), std::inserter(_numsVecSet, _numsVecSet.end()));
  // use adjacent_find to compare elements with ShortestSpanPredicate functor.
  std::adjacent_find(_numsVecSet.begin(), _numsVecSet.end(), 
                     ShortestSpanPredicate(shortest));
  // ShortestSpanPredicate functor edits shortest by ref and finds the shortest
  // span in the set.
  return (shortest);
};

int Span::longestSpan() {
  // longestSpan using min_element and max_element algorithms.
  if (_numsVec.size() <= 1)
    throw NotEnoughElementsException();
  std::vector<int>::iterator min = std::min_element(_numsVec.begin(), _numsVec.end());
  std::vector<int>::iterator max = std::max_element(_numsVec.begin(), _numsVec.end());
  return ((*max) - (*min));
};

void Span::displaySpan() {
  std::cout << "Span Contents: [ ";
  for (std::vector<int>::iterator it = _numsVec.begin(); it != _numsVec.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << "]" << std::endl;
  std::cout << "Span Size: " << _numsVec.size() << std::endl;
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
