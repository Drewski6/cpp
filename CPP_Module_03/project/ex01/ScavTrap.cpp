/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:14:06 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 15:59:29 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

// Constructors , Copy Constructor, Destructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _gateKeeperMode(false) {
  _hp = 100;
  _ep = 50;
  _atk = 20;
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
  return (*this);
};

// Public Methods
void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << _name << " is in Gate keeper mode." << std::endl;
  _gateKeeperMode = true;
  return;
};

void ScavTrap::attack(const std::string &target) {
  if (!_useEnergy(1))
    return;
  std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
            << _atk << " points of damage!" << std::endl;
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
