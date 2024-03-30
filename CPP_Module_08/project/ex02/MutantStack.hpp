/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:12:14 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/30 10:36:23 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <stack>
#include <cstddef>

template <typename T>
class MutantStack {
public:
  // Constructors , Copy Constructor, Destructor
  MutantStack(void);
  MutantStack(MutantStack const &source);
  ~MutantStack(void);

  // Overloaded Operators
  MutantStack &operator=(MutantStack const &rhs);

  // Public Methods
  T &top();
  bool empty();
  size_t size();
  void push(const T &value);
  void pop();
  
private:
  // Only deque available as underlying container for my MutatedStack.
  std::stack<T> _stack;
};

#include "MutantStack.tpp"
