/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:26:55 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/18 17:19:13 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructors , Copy Constructor, Destructor
Ice::Ice(void) : AMateria("ice"){};

Ice::Ice(Ice const &source) : AMateria("ice") { *this = source; };
Ice::~Ice(void){};

// Overloaded Operators
Ice &Ice::operator=(Ice const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods
Ice *Ice::clone() const {
  Ice *retIce = new Ice;
  return retIce;
};

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
};
