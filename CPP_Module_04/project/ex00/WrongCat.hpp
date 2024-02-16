/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:19 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 19:16:24 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

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
