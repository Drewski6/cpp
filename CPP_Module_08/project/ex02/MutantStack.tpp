/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:12:04 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/30 10:55:13 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Constructors , Copy Constructor, Destructor

template <typename T>
MutantStack<T>::MutantStack(void) {};

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &source) { *this = source; };

template <typename T>
MutantStack<T>::~MutantStack(void) {};

// Overloaded Operators
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &rhs) {
  if (this == &rhs)
    return *this;
  this->_stack = rhs._stack;
  return *this;
};

// Public Methods
template <typename T>
T &MutantStack<T>::top() {
  return _stack.top();
};

template <typename T>
bool MutantStack<T>::empty() {
  return _stack.empty();
};

template <typename T>
size_t MutantStack<T>::size() {
  return _stack.size();
};

template <typename T>
void MutantStack<T>::push(const T &value) {
  return _stack.push(value);
};

template <typename T>
void MutantStack<T>::pop() {
  return _stack.pop();
};
