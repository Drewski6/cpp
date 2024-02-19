/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:26:06 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/19 18:34:43 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter {
public:
  // Constructors , Copy Constructor, Destructor
  Character(std::string name);

  Character(Character const &source);
  ~Character(void);

  // Overloaded Operators
  Character &operator=(Character const &rhs);

  // Functions to implement from ICharacter class
  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

  void printInventory(void);
  AMateria *putOnFloor(int idx);

private:
  std::string _name;
  AMateria *_materias[4];
};
