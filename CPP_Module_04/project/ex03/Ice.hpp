/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:26:48 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/17 15:37:56 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria {
public:
  // Constructors , Copy Constructor, Destructor
  Ice(void);

  Ice(Ice const &source);
  ~Ice(void);

  // Overloaded Operators
  Ice &operator=(Ice const &rhs);

  // Public Methods
  Ice *clone() const;
  void use(ICharacter& target);

private:
};
