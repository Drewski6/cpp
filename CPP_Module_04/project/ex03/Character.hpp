/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:26:06 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/17 15:47:44 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter {
public:
  // Constructors , Copy Constructor, Destructor
  Character(void);

  Character(Character const &source);
  ~Character(void);

  // Overloaded Operators
  Character &operator=(Character const &rhs);

  // Functions to implement from ICharacter class
  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

private:
  std::string name;
};
