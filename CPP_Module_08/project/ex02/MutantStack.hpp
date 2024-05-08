/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:12:14 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/08 21:23:27 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <string>

// template <typename T, typename U = std::deque<T> >
template <typename T>
class MutantStack : public std::stack<T> {
public:
  // Constructors , Copy Constructor, Destructor
  MutantStack(void);
  MutantStack(MutantStack const &source);
  ~MutantStack(void);

  // Overloaded Operators
  MutantStack &operator=(MutantStack const &rhs);

  // Creating new type with name "iterator" which is a "typename
  // std::stack<T>::container_type::iterator" This type acts as an iterator for
  // whichever type of iterator we want to return for the underlying container.
  typedef typename std::stack<T>::container_type::iterator iterator;

  // Returning our new type "iterator" by calling begin, end, etc for the
  // underlying container by accessing through c. c is the underlying container
  // object in the stack class. So we're calling its begin method rather than
  // making our own.
  iterator begin() { return std::stack<T>::c.begin(); }
  iterator end() { return std::stack<T>::c.end(); }
  iterator rbegin() { return std::stack<T>::c.rbegin(); }
  iterator rend() { return std::stack<T>::c.rend(); }

  // Same for const versions of our iterators.
  iterator cbegin() { return std::stack<T>::c.cbegin(); }
  iterator cend() { return std::stack<T>::c.cend(); }
  iterator crbegin() { return std::stack<T>::c.crbegin(); }
  iterator crend() { return std::stack<T>::c.crend(); }
};

#include "MutantStack.tpp"
