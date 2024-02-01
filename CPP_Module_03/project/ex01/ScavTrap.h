/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:13:57 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/01 13:18:05 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
public:
  // Constructors , Copy Constructor, Destructor
  ScavTrap(std::string name);

  ScavTrap(ScavTrap const &source);
  ~ScavTrap(void);

  // Overloaded Operators
  ScavTrap &operator=(ScavTrap const &rhs);

private:
};

#endif // SCAVTRAP_H //
