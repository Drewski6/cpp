/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:54:28 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 19:25:35 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
public:
  // Constructors , Copy Constructor, Destructor
  WrongAnimal(void);

  WrongAnimal(WrongAnimal const &source);
  ~WrongAnimal(void);

  // Overloaded Operators
  WrongAnimal &operator=(WrongAnimal const &rhs);

  // Public Methods
  std::string getType(void) const;
  void makeSound(void) const;

protected:
  std::string type;
};
