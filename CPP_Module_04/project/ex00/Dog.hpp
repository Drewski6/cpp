/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:19 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/20 13:27:16 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

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
