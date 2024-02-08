/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:19 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/03 19:31:18 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
public:
  // Constructors , Copy Constructor, Destructor
  WrongCat(void);

  WrongCat(WrongCat const &source);
  ~WrongCat(void);

  // Overloaded Operators
  WrongCat &operator=(WrongCat const &rhs);

  // Public Methods
  void makeSound(void) const;

private:
};

#endif // WRONGCAT_H //
