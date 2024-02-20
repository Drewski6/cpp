/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:54:28 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:53 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class AAnimal {
public:
  // Constructors , Copy Constructor, Destructor
  AAnimal(void);
  AAnimal(std::string type_val);
  AAnimal(AAnimal const &source);
  virtual ~AAnimal(void);

  // Overloaded Operators
  AAnimal &operator=(AAnimal const &rhs);

  // Public Methods
  std::string getType(void) const;
  virtual void makeSound(void) const = 0;

protected:
  std::string type;
};
