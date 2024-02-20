/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:30 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/20 13:27:37 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors , Copy Constructor, Destructor
Cat::Cat(void) : Animal("Cat") {
  std::cout << "Constructor for Cat" << std::endl;
};

Cat::Cat(Cat const &source) : Animal(source) {
  std::cout << "Copy Constructor for Cat" << std::endl;
  *this = source;
};

Cat::~Cat(void) { std::cout << "Destructor for Cat" << std::endl; };

// Overloaded Operators
Cat &Cat::operator=(Cat const &rhs) {
  if (this == &rhs)
    return (*this);
  return (*this);
};

// Public Methods
void Cat::makeSound(void) const { std::cout << "Meow....." << std::endl; };

// Private Methods
