/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:19 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/08 19:02:00 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "A_Animal.h"
#include "Brain.h"

class Dog : public A_Animal {
public:
  // Constructors , Copy Constructor, Destructor
  Dog(void);

  Dog(Dog const &source);
  ~Dog(void);

  // Overloaded Operators
  Dog &operator=(Dog const &rhs);

  // Public Methods
  void makeSound(void) const;
  std::string &getIdea(int idea_index);
  void setIdea(int idea_index, std::string idea_content);

private:
  // Private Attributes
  Brain *brain;
};

#endif // DOG_H //
