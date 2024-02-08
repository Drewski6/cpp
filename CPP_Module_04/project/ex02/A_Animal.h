/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:54:28 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/08 19:01:22 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ANIMAL_H
#define A_ANIMAL_H

#include <iostream>
#include <string>

class A_Animal {
public:
  // Constructors , Copy Constructor, Destructor
  A_Animal(void);

  A_Animal(A_Animal const &source);
  virtual ~A_Animal(void);

  // Overloaded Operators
  A_Animal &operator=(A_Animal const &rhs);

  // Public Methods
  std::string getType(void) const;
  virtual void makeSound(void) const = 0;

protected:
  std::string type;
};

#endif // A_ANIMAL_H //
