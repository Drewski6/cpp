/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:26:06 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/09 15:28:51 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.h"

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

#endif // CHARACTER_H //
