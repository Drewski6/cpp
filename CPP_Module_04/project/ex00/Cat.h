/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:19 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/03 17:10:30 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
public:
  // Constructors , Copy Constructor, Destructor
  Cat(void);

  Cat(Cat const &source);
  ~Cat(void);

  // Overloaded Operators
  Cat &operator=(Cat const &rhs);

  // Public Methods
  void makeSound(void) const;

private:
};

#endif // CAT_H //
