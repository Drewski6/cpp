/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:14:06 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/03 08:31:30 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

// Constructors , Copy Constructor, Destructor
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  _hp = 100;
  _ep = 100;
  _atk = 30;
  std::cout << "Constructor called for new FragTrap " << _name << std::endl;
};

FragTrap::FragTrap(FragTrap const &source) : ClapTrap(source) {
  std::cout << "Copy Constructor called for new FragTrap " << _name
            << std::endl;
};
FragTrap::~FragTrap(void) {
  std::cout << "Destructor called for FragTrap " << _name << std::endl;
};

// Overloaded Operators
FragTrap &FragTrap::operator=(FragTrap const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << _name << " would like a high five!!" << std::endl;
  return;
};

void FragTrap::attack(const std::string &target) {
  if (!_useEnergy(1))
    return;
  std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
            << _atk << " points of damage!" << std::endl;
};

void FragTrap::printStatus(void) {
  std::cout << "\t" << _name << ": \n"
            << "\tHealth: " << _hp << "\n"
            << "\tEnergy: " << _ep << "\n"
            << "\tAttack: " << _atk << "\n"
            << std::endl;
}

// Private Methods
