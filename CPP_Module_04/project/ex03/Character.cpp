/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:25:55 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/17 15:49:25 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructors , Copy Constructor, Destructor
Character::Character(void) {};

Character::Character(Character const &source) { *this = source; };
Character::~Character(void){};

// Overloaded Operators
Character &Character::operator=(Character const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods
std::string const &Character::getName() const {
  return (name);
};

void Character::equip(AMateria *m) {
  (void)m;
};

void Character::unequip(int idx) {
  (void)idx;
};

void Character::use(int idx, ICharacter &target) {
  (void)idx;
  (void)target;
};

// Private Methods
