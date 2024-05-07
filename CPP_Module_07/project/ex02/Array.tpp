/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:34:12 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/30 08:26:25 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Constructors , Copy Constructor, Destructor
template <typename T> Array<T>::Array(void) : _array(new T[0]), _size(0){};

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n){};

template <typename T>
Array<T>::Array(Array const &source) : _array(new T[0]), _size(0) {
  *this = source;
};

template <typename T> Array<T>::~Array(void) { delete[] _array; };

// Exception Class Implementation
template <typename T> Array<T>::OutOfBoundsException::OutOfBoundsException(){};
template <typename T>
Array<T>::OutOfBoundsException::~OutOfBoundsException() throw(){};
template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
  return ("Error: Index out of bounds.");
}

// Overloaded Operators
template <typename T> Array<T> &Array<T>::operator=(Array const &rhs) {
  if (this == &rhs)
    return (*this);
  _size = rhs._size;
  delete[] this->_array;
  this->_array = new T[_size];
  for (unsigned int i = 0; i < _size; i++) {
    (this->_array)[i] = (rhs._array)[i];
  }
  return (*this);
};

template <typename T> T &Array<T>::operator[](unsigned int index) {
  if (index >= _size)
    throw Array<T>::OutOfBoundsException();
  return _array[index];
};

template <typename T> unsigned int Array<T>::size() { return (_size); }

template <typename T> void Array<T>::print() {
  // Obviously this isn't the best way to print contents of an array,
  // but it works for testing.
  for (unsigned int i = 0; i < _size; i++) {
    std::cout << _array[i];
    if (i != _size - 1)
      std::cout << ", ";
  }
  std::cout << std::endl;
}
