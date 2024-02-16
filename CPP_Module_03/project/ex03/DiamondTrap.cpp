/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:35:01 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 18:09:40 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructors , Copy Constructor, Destructor
DiamondTrap::DiamondTrap(std::string name_val)
    : ClapTrap(name_val + "_clap_name"), FragTrap(name_val), ScavTrap(name_val),
      _name(name_val) {
  std::cout << "Constructor called for new DiamondTrap " << _name << std::endl;
  FragTrap::_hp = 100;
  ScavTrap::_ep = 50;
  FragTrap::_atk = 30;
};

DiamondTrap::DiamondTrap(DiamondTrap const &source)
    : ClapTrap(source._name), FragTrap(source._name), ScavTrap(source._name) {
  std::cout << "Copy Constructor called for new DiamondTrap " << _name
            << std::endl;
  *this = source;
};

DiamondTrap::~DiamondTrap(void) {
  std::cout << "Destructor called for DiamondTrap " << _name << std::endl;
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
  ScavTrap::attack(target);
};

void DiamondTrap::whoAmI(void) {
  std::cout << "DiamondTrap name: " << _name << "\n"
            << "ClapTrap name   : " << ClapTrap::_name << std::endl;
  return;
};

void DiamondTrap::printStatus(void) {
  std::cout << "\t" << _name << ": \n"
            << "\tClapTrap::_name: " << ClapTrap::_name << "\n"
            << "\tHealth: " << FragTrap::_hp << "\n"
            << "\tEnergy: " << ScavTrap::_ep << "\n"
            << "\tAttack: " << FragTrap::_atk << "\n"
            << "\tGate Keeper Mode: " << (_gateKeeperMode ? "true" : "false")
            << "\n"
            << std::endl;
};
