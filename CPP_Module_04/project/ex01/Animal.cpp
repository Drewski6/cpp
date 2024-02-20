/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:54:12 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/20 15:43:27 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors , Copy Constructor, Destructor
Animal::Animal(void) { 
  std::cout << "Default Constructor for Animal" << std::endl; 
};

Animal::Animal(std::string type_val) : type(type_val) { 
  std::cout << "Argument Constructor for Animal" << std::endl; 
};

Animal::Animal(Animal const &source) : type(source.type) {
  std::cout << "Copy Constructor for Animal" << std::endl;
  *this = source;
};

Animal::~Animal(void) { std::cout << "Destructor for Animal" << std::endl; };

// Overloaded Operators
// Shallow copy intentional
Animal &Animal::operator=(Animal const &rhs) {
  if (this == &rhs)
    return (*this);
  return (*this);
};

// We can still have a default implementation of makeSound.
// I decided to make the print statement very obvious.
// We could easily have an empty function as well.
// However, we do need to have an implementation because this is not 
// a pure virtual function.
void Animal::makeSound(void) const {
  std::cout << "Animal class default makeSound call" << std::endl;
};

std::string Animal::getType(void) const { return type; };

