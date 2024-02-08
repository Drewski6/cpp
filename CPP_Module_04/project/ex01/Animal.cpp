/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:54:12 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/06 16:23:03 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

// Constructors , Copy Constructor, Destructor
Animal::Animal(void) { std::cout << "Constructor for Animal" << std::endl; };

Animal::Animal(Animal const &source) {
  std::cout << "Copy Constructor for Animal" << std::endl;
  *this = source;
};
Animal::~Animal(void) { std::cout << "Destructor for Animal" << std::endl; };

// Overloaded Operators
Animal &Animal::operator=(Animal const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods
void Animal::makeSound(void) const { 
	std::cout << "Animal class default makeSound call" << std::endl;
	return; };

std::string Animal::getType(void) const { return type; };

// Private Methods
