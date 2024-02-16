/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:54:12 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 20:48:04 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Constructors , Copy Constructor, Destructor
AAnimal::AAnimal(void) { std::cout << "Constructor for AAnimal" << std::endl; };

AAnimal::AAnimal(AAnimal const &source) {
  std::cout << "Copy Constructor for AAnimal" << std::endl;
  *this = source;
};
AAnimal::~AAnimal(void) { std::cout << "Destructor for AAnimal" << std::endl; };

// Overloaded Operators
AAnimal &AAnimal::operator=(AAnimal const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods

std::string AAnimal::getType(void) const { return type; };

// Private Methods
