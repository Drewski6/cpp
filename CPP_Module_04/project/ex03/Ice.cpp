/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:26:55 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 19:30:08 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructors , Copy Constructor, Destructor
Ice::Ice(void){};

Ice::Ice(Ice const &source) { *this = source; };
Ice::~Ice(void){};

// Overloaded Operators
Ice &Ice::operator=(Ice const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods

// Private Methods
