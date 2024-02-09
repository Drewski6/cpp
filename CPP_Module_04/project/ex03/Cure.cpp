/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:26:34 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/09 15:26:39 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.h"

// Constructors , Copy Constructor, Destructor
Cure::Cure(void){};

Cure::Cure(Cure const &source) { *this = source; };
Cure::~Cure(void){};

// Overloaded Operators
Cure &Cure::operator=(Cure const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods

// Private Methods

