/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:14:06 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/01 14:13:16 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScavTrap.h"
#include "ClapTrap.h"

// Constructors , Copy Constructor, Destructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "Constructor called for new ScavTrap " << _name << std::endl;
};

ScavTrap::ScavTrap(ScavTrap const &source) : ClapTrap(source) {
  std::cout << "Copy Constructor called for new ScavTrap " << _name
            << std::endl;
};
ScavTrap::~ScavTrap(void) {
  std::cout << "Destructor called for ScavTrap " << _name << std::endl;
};

// Overloaded Operators
ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods

// Private Methods
