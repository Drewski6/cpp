/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:26:34 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/19 15:37:24 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Constructors , Copy Constructor, Destructor
Cure::Cure(void)
    : AMateria("cure"){
          // std::cout << "Cure Constructor." << std::endl;
      };

Cure::Cure(Cure const &source) : AMateria("cure") { *this = source; };
Cure::~Cure(void){};

// Overloaded Operators
Cure &Cure::operator=(Cure const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods
Cure *Cure::clone() const {
  Cure *retCure = new Cure;
  return retCure;
};

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
};
