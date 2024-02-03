/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:30 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/03 17:10:48 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.h"

// Constructors , Copy Constructor, Destructor
Dog::Dog(void) : Animal() {
  Animal::type = "Dog";
  std::cout << "Constructor for Dog" << std::endl;
};

Dog::Dog(Dog const &source) : Animal() {
  std::cout << "Copy Constructor for Dog" << std::endl;
  *this = source;
};
Dog::~Dog(void) { std::cout << "Destructor for Dog" << std::endl; };

// Overloaded Operators
Dog &Dog::operator=(Dog const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods
void Dog::makeSound(void) const { std::cout << "Woof Woof!" << std::endl; };

// Private Methods
