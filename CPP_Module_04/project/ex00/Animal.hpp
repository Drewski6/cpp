/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:54:28 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/20 13:25:09 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal {
public:
  // Constructors , Copy Constructor, Destructor
  Animal(void);
  Animal(std::string type_val);
  Animal(Animal const &source);
  virtual ~Animal(void);

  // Overloaded Operators
  Animal &operator=(Animal const &rhs);

  // Public Methods
  std::string getType(void) const;
  virtual void makeSound(void) const;

protected:
  std::string type;
};
