/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:19 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/09 14:36:08 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "AAnimal.h"
#include "Brain.h"

class Cat : public AAnimal {
public:
  // Constructors , Copy Constructor, Destructor
  Cat(void);

  Cat(Cat const &source);
  ~Cat(void);

  // Overloaded Operators
  Cat &operator=(Cat const &rhs);

  // Public Methods
  void makeSound(void) const;
  std::string &getIdea(int idea_index);
  void setIdea(int idea_index, std::string idea_content);

private:
  Brain *brain;
};

#endif // CAT_H //
