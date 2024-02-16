/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:28:04 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 19:31:06 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors , Copy Constructor, Destructor
MateriaSource::MateriaSource(void){};

MateriaSource::MateriaSource(MateriaSource const &source) { *this = source; };
MateriaSource::~MateriaSource(void){};

// Overloaded Operators
MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods

// Private Methods
