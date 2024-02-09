/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:25:55 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/09 15:26:04 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.h"

// Constructors , Copy Constructor, Destructor
Character::Character(void){};

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

// Private Methods

