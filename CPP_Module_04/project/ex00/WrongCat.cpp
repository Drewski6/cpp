/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:30 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/03 19:26:30 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.h"

// Constructors , Copy Constructor, Destructor
WrongCat::WrongCat(void) : WrongAnimal() {
  WrongAnimal::type = "WrongCat";
  std::cout << "Constructor for WrongCat" << std::endl;
};

WrongCat::WrongCat(WrongCat const &source) : WrongAnimal() {
  std::cout << "Copy Constructor for WrongCat" << std::endl;
  *this = source;
};
WrongCat::~WrongCat(void) {
  std::cout << "Destructor for WrongCat" << std::endl;
};

// Overloaded Operators
WrongCat &WrongCat::operator=(WrongCat const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods
void WrongCat::makeSound(void) const {
  std::cout << "Wrong Meow!!!" << std::endl;
};

// Private Methods
