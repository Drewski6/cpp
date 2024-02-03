/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:13:57 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/02 10:06:01 by dpentlan         ###   ########.fr       */
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

  // Public Methods
  void guardGate();
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void printStatus(void);

private:
  bool _gateKeeperMode;
};

#endif // SCAVTRAP_H //