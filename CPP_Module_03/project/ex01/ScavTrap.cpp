/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:14:06 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/01 11:20:03 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScavTrap.h"

// Constructors , Copy Constructor, Destructor
ScavTrap::ScavTrap(void){};

ScavTrap::ScavTrap(ScavTrap const &source) { *this = source; };
ScavTrap::~ScavTrap(void){};

// Overloaded Operators
ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods

// Private Methods
