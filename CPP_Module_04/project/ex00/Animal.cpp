/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:54:12 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/03 15:54:24 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"

// Constructors , Copy Constructor, Destructor
Animal::Animal(void){};

Animal::Animal(Animal const &source) { *this = source; };
Animal::~Animal(void){};

// Overloaded Operators
Animal &Animal::operator=(Animal const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods

// Private Methods
