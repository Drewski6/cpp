/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:26:22 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/18 17:18:48 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "Character.hpp"
#include <iostream>

class Cure : public AMateria {
public:
  // Constructors , Copy Constructor, Destructor
  Cure(void);

  Cure(Cure const &source);
  ~Cure(void);

  // Overloaded Operators
  Cure &operator=(Cure const &rhs);

  // Public Methods
  Cure *clone() const;
  void use(ICharacter &target);

private:
};
