/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:25:14 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/19 22:05:19 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructors , Copy Constructor, Destructor
AMateria::AMateria(std::string const &type_val) : _type(type_val){};
AMateria::AMateria(AMateria const &source) { *this = source; };
AMateria::~AMateria(void){};

// Overloaded Operators
AMateria &AMateria::operator=(AMateria const &rhs) {
  if (this == &rhs)
    return (*this);
  return (*this);
};

// Public Methods
void AMateria::use(ICharacter &target) {
  // Not pure virtual function so does nothing as default implementation
  (void)target;
};

std::string const &AMateria::getType() const { return _type; };
