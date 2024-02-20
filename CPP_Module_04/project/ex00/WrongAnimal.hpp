/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:54:28 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/20 17:11:53 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
public:
  // Constructors , Copy Constructor, Destructor
  WrongAnimal(void);
  WrongAnimal(std::string type_val);
  WrongAnimal(WrongAnimal const &source);
  ~WrongAnimal(void);

  // Overloaded Operators
  WrongAnimal &operator=(WrongAnimal const &rhs);

  // Public Methods
  std::string getType(void) const;
  // makeSound is intentionally not virtual here
  void makeSound(void) const;

protected:
  std::string type;
};
