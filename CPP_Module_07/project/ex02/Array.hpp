/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:24:48 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/07 16:43:54 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <ostream>

template <typename T> class Array {
public:
  // Constructors , Copy Constructor, Destructor
  Array(void);
  Array(unsigned int n);
  Array(const Array &source);
  ~Array();

  // Overloaded Operators
  Array &operator=(Array const &rhs);
  T &operator[](unsigned int index);

  // Public methods
  unsigned int size();
  void print() const;

  // Exception Classes
  class OutOfBoundsException : public std::exception {
  public:
    OutOfBoundsException();
    virtual ~OutOfBoundsException() throw();
    virtual const char *what() const throw();
  };

private:
  T *_array;
  unsigned int _size;
};

// Overloaded Stream Insertion Operator
template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &b);

#include "Array.tpp"
