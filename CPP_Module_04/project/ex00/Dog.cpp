/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:30 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/20 13:27:33 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors , Copy Constructor, Destructor
Dog::Dog(void) : Animal("Dog") {
  std::cout << "Constructor for Dog" << std::endl;
};

Dog::Dog(Dog const &source) : Animal(source) {
  std::cout << "Copy Constructor for Dog" << std::endl;
  *this = source;
};

Dog::~Dog(void) { std::cout << "Destructor for Dog" << std::endl; };

// Overloaded Operators
Dog &Dog::operator=(Dog const &rhs) {
  if (this == &rhs)
    return (*this);
  return (*this);
};

// Public Methods
void Dog::makeSound(void) const { std::cout << "Woof Woof!" << std::endl; };

// Private Methods
