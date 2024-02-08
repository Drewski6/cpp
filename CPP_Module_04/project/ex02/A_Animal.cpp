/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:54:12 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/08 19:00:44 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.h"

// Constructors , Copy Constructor, Destructor
A_Animal::A_Animal(void) { std::cout << "Constructor for A_Animal" << std::endl; };

A_Animal::A_Animal(A_Animal const &source) {
  std::cout << "Copy Constructor for A_Animal" << std::endl;
  *this = source;
};
A_Animal::~A_Animal(void) { std::cout << "Destructor for A_Animal" << std::endl; };

// Overloaded Operators
A_Animal &A_Animal::operator=(A_Animal const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods
void A_Animal::makeSound(void) const { 
	std::cout << "A_Animal class default makeSound call" << std::endl;
	return; };

std::string A_Animal::getType(void) const { return type; };

// Private Methods
