/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:25:14 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/09 17:25:13 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

// Constructors , Copy Constructor, Destructor
AMateria::AMateria(std::string const & type) {
  // Constructor
  (void)type;
};

AMateria::AMateria(AMateria const &source) { *this = source; };
AMateria::~AMateria(void){};

// Overloaded Operators
AMateria &AMateria::operator=(AMateria const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods
  void AMateria::use(ICharacter& target) {
    (void) target;
  };

// Private Methods

