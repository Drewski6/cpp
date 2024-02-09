/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:25:34 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/09 17:12:06 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>

class ICharacter;

class AMateria {
protected:
  // [...]
public:
  // Constructors , Copy Constructor, Destructor
  AMateria(std::string const & type);
  AMateria(AMateria const &source);
  ~AMateria(void);

  // Overloaded Operators
  AMateria &operator=(AMateria const &rhs);

  // [...]
  std::string const & getType() const; //Returns the materia type
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};

#endif // AMATERIA_H //
