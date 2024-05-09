/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:35:09 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/29 14:26:44 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <functional>

class Span {
public:
  // Constructors , Copy Constructor, Destructor
  Span(unsigned int N);
  Span(Span const &source);
  ~Span(void);

  // Overloaded Operators
  Span &operator=(Span const &rhs);

  // Public Methods
  void addNumber(int num);
  int shortestSpan();
  int longestSpan();
  void displaySpan();

  // Exception Classes
  class OutOfSpaceException : public std::exception {
  public:
    OutOfSpaceException();
    virtual ~OutOfSpaceException() throw();
    virtual const char *what() const throw();
  };

  class NotEnoughElementsException : public std::exception {
  public:
    NotEnoughElementsException();
    virtual ~NotEnoughElementsException() throw();
    virtual const char *what() const throw();
  };

  // Templated Functions
  // (implementations allowed for templated functions per the subject)
  template <typename T>
  void addRange(typename T::iterator begin, typename T::iterator last) {
    if (std::distance(begin, last) + _numsVec.size() > _maxVecSize)
      throw OutOfSpaceException();
    _numsVec.insert(_numsVec.end(), begin, last);
  };

  // Functor for shortestSpan
  class ShortestSpanPredicate {
  public:
    ShortestSpanPredicate(int& shortest);
    bool operator()(int a, int b) const;
  private:
    int &_shortest;
  };

private:
  std::vector<int> _numsVec;
  unsigned int _maxVecSize;
};

