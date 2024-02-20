/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:54:12 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/20 15:48:44 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Constructors , Copy Constructor, Destructor
AAnimal::AAnimal(void) { 
  std::cout << "Default Constructor for AAnimal" << std::endl;
};

AAnimal::AAnimal(std::string type_val) : type(type_val) {
  std::cout << "Argument Constructor for AAnimal" << std::endl;
};

AAnimal::AAnimal(AAnimal const &source) : type(source.type) {
  std::cout << "Copy Constructor for AAnimal" << std::endl;
  *this = source;
};

AAnimal::~AAnimal(void) { std::cout << "Destructor for AAnimal" << std::endl; };

// Overloaded Operators
// Shallow copy intentional
AAnimal &AAnimal::operator=(AAnimal const &rhs) {
  if (this == &rhs)
    return (*this);
  return (*this);
};

// Note thanks to the pure virtual function makeSound, we dont need an implementation

std::string AAnimal::getType(void) const { return type; };
