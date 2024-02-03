/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:35:01 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/03 09:22:33 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"
#include "FragTrap.h"
#include "ScavTrap.h"

// Constructors , Copy Constructor, Destructor
DiamondTrap::DiamondTrap(std::string name_val)
    : ClapTrap(name_val + "_clap_name"), ScavTrap(name_val), FragTrap(name_val),
      _name(name_val) {
  std::cout << "Constructor called for new DiamondTrap " << _name << std::endl;
};

DiamondTrap::DiamondTrap(DiamondTrap const &source)
    : ClapTrap(source._name), ScavTrap(source._name), FragTrap(source._name) {
  std::cout << "Copy Constructor called for new DiamondTrap " << _name
            << std::endl;
  *this = source;
};

DiamondTrap::~DiamondTrap(void) {
  std::cout << "Destructor called for new DiamondTrap " << _name << std::endl;
};

// Overloaded Operators
DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods
void DiamondTrap::attack(const std::string &target) {
  if (!_useEnergy(1))
    return;
  std::cout << "DiamondTrap " << _name << " attacks " << target << ", causing "
            << _atk << " points of damage!" << std::endl;
  return;
};

void DiamondTrap::printStatus(void) {
  std::cout << "\t" << _name << ": \n"
            << "\tClapTrap::_name: " << ClapTrap::_name << "\n"
            << "\tHealth: " << _hp << "\n"
            << "\tEnergy: " << _ep << "\n"
            << "\tAttack: " << _atk << "\n"
            << std::endl;
};

// Private Methods
