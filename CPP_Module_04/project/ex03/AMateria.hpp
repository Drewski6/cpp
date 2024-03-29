/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:25:34 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/19 21:58:06 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ICharacter;

class AMateria {
protected:
  std::string _type;

public:
  // Constructors , Copy Constructor, Destructor
  AMateria(std::string const &type_val);
  AMateria(AMateria const &source);
  virtual ~AMateria(void);

  // Overloaded Operators
  AMateria &operator=(AMateria const &rhs);

  std::string const &getType() const; // Returns the materia type

  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};
