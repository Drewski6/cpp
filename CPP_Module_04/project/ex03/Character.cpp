/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:25:55 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/19 22:23:06 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructors , Copy Constructor, Destructor
Character::Character(std::string name) : _name(name) {
  // Initialization of _materias array
  for (int i = 0; i < 4; i++) {
    _materias[i] = NULL;
  }
};

Character::Character(Character const &source) : _name(source._name) {
  // Initialization of _materias array
  for (int i = 0; i < 4; i++) {
    _materias[i] = NULL;
  }
  *this = source;
};

Character::~Character(void) {
  // Delete all active _materias
  for (int i = 0; i < 4; i++) {
    if (_materias[i]) {
      delete _materias[i];
      _materias[i] = NULL;
    }
  }
};

// Overloaded Operators
Character &Character::operator=(Character const &rhs) {
  if (this == &rhs)
    return (*this);
  // clone each _materia item (ie DEEP COPY)
  for (int i = 0; i < 4; i++) {
    if (rhs._materias[i])
      (*this)._materias[i] = rhs._materias[i]->clone();
  }
  return (*this);
};

// Public Methods
std::string const &Character::getName() const { return (_name); };

// Copy address of new AMateria to Characters _materia array
void Character::equip(AMateria *m) {
  if (m) {
    for (int i = 0; i < 4; i++) {
      if (!_materias[i]) {
        _materias[i] = m;
        return;
      }
    }
  }
};

// unequiped items cannot be deleted per subject
void Character::unequip(int idx) {
  if (idx >= 0 && idx <= 4 && _materias[idx])
    _materias[idx] = NULL;
};

// Subject does not say if a used item should be deleted or not. I do here.
void Character::use(int idx, ICharacter &target) {
  if (idx >= 0 && idx <= 4 && _materias[idx]) {
    _materias[idx]->use(target);
    delete _materias[idx];
    _materias[idx] = NULL;
  }
};

// My addition for making evaluations easier :)
void Character::printInventory(void) {
  std::cout << "Inventory for Character named '" << _name << "':" << std::endl;
  for (int i = 0; i < 4; i++) {
    std::cout << "_materias[" << i << "]: " << _materias[i];
    if (_materias[i]) {
      std::cout << " type: " << _materias[i]->getType();
    }
    std::cout << std::endl;
  }
};

// My solution for problem posed in subject. Basically a getter for a _materia.
AMateria *Character::putOnFloor(int idx) { return _materias[idx]; };
