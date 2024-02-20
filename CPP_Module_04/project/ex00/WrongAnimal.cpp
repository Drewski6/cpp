/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:54:12 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/20 17:12:32 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors , Copy Constructor, Destructor
WrongAnimal::WrongAnimal(void) {
  std::cout << "Default Constructor for WrongAnimal" << std::endl;
};

WrongAnimal::WrongAnimal(std::string type_val) : type(type_val) {
  std::cout << "Argument Constructor for WrongAnimal" << std::endl;
};

WrongAnimal::WrongAnimal(WrongAnimal const &source) {
  std::cout << "Copy Constructor for WrongAnimal" << std::endl;
  *this = source;
};
WrongAnimal::~WrongAnimal(void) {
  std::cout << "Destructor for WrongAnimal" << std::endl;
};

// Overloaded Operators
WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods
void WrongAnimal::makeSound(void) const {
  std::cout << "Wrong Animal Sound! lol" << std::endl;
  return;
};

std::string WrongAnimal::getType(void) const { return type; };

// Private Methods
