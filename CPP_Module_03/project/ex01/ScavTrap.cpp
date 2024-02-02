/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:14:06 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/02 10:09:23 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScavTrap.h"
#include "ClapTrap.h"

// Constructors , Copy Constructor, Destructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  _hp = 100;
  _ep = 50;
  _atk = 20;
  _gateKeeperMode = false;
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
void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << _name << " is now in Gate keeper mode."
            << std::endl;
  _gateKeeperMode = true;
  return;
};

void ScavTrap::attack(const std::string &target) {
  if (!_useEnergy(1))
    return;
  std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
            << _atk << " points of damage!" << std::endl;
};

void ScavTrap::takeDamage(unsigned int amount) {
  _hp -= amount;
  std::cout << "ScavTrap " << _name << " takes " << amount
            << " points of damage!" << std::endl;
};

void ScavTrap::beRepaired(unsigned int amount) {
  if (!_useEnergy(1))
    return;
  _hp += amount;
  std::cout << "ScavTrap " << _name << " heals itself for " << amount
            << " points of health!" << std::endl;
};

void ScavTrap::printStatus(void) {
  std::cout << "\t" << _name << ": \n"
            << "\tHealth: " << _hp << "\n"
            << "\tEnergy: " << _ep << "\n"
            << "\tAttack: " << _atk << "\n"
            << "\tGate Keeper Mode: " << (_gateKeeperMode ? "true" : "false")
            << "\n"
            << std::endl;
}

// Private Methods
