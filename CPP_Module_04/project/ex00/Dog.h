/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:19 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/03 17:10:43 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
public:
  // Constructors , Copy Constructor, Destructor
  Dog(void);

  Dog(Dog const &source);
  ~Dog(void);

  // Overloaded Operators
  Dog &operator=(Dog const &rhs);

  // Public Methods
  void makeSound(void) const;

private:
};

#endif // DOG_H //
