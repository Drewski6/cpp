/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:37 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/01 14:16:49 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

// Constructors , Copy Constructor, Destructor
// No default construtor because subject indicates a name should be passed.
ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _atk(0) {
  std::cout << "Constructor called for new ClapTrap " << _name << std::endl;
};

ClapTrap::ClapTrap(ClapTrap const &source) {
  this->_name = source._name;
  this->_hp = source._hp;
  this->_ep = source._ep;
  this->_atk = source._atk;
  std::cout << "Copy Constructor called for new ClapTrap " << _name
            << std::endl;
};

ClapTrap::~ClapTrap(void) {
  std::cout << "Destructor called for ClapTrap " << _name << std::endl;
};

// Overloaded Operators
ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods
void ClapTrap::attack(const std::string &target) {
  if (!_useEnergy(1))
    return;
  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << _atk << " points of damage!" << std::endl;
};

void ClapTrap::takeDamage(unsigned int amount) {
  _hp -= amount;
  std::cout << "ClapTrap " << _name << " takes " << amount
            << " points of damage!" << std::endl;
};

void ClapTrap::beRepaired(unsigned int amount) {
  if (!_useEnergy(1))
    return;
  _hp += amount;
  std::cout << "ClapTrap " << _name << " heals itself for " << amount
            << " points of health!" << std::endl;
};

void ClapTrap::printStatus(void) {
  std::cout << "\t" << _name << ": \n"
            << "\tHealth: " << _hp << "\n"
            << "\tEnergy: " << _ep << "\n"
            << "\tAttack: " << _atk << "\n"
            << std::endl;
}

// Protected Methods
bool ClapTrap::_useEnergy(int amount) {
  if (!_healthCheck(amount))
    return (false);
  if (!_energyCheck(amount))
    return (false);
  _ep -= amount;
  return true;
}

bool ClapTrap::_healthCheck(int amount) {
  // Checks if ClapTrap has health.
  // Returns true if health is > 0.
  // Returns false if health is <= 0.
  if (this->_hp < amount) {
    std::cout << _name << " has no more health points and cannot do anything!"
              << std::endl;
    return false;
  }
  return true;
};

bool ClapTrap::_energyCheck(int amount) {
  // Checks if ClapTrap has energy.
  // Returns true if energy is available.
  // Returns false if no energy is available.
  if (this->_ep < amount) {
    std::cout << _name << " has no more energy points and cannot do anything!"
              << std::endl;
    return false;
  }
  return true;
};
