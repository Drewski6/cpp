/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:26:06 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 19:29:36 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Character {
public:
  // Constructors , Copy Constructor, Destructor
  Character(void);

  Character(Character const &source);
  ~Character(void);

  // Overloaded Operators
  Character &operator=(Character const &rhs);

private:
};
