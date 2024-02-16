/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:13:57 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 16:39:40 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

// Adding virtual to avoid the "Diamond Problem"
class ScavTrap : virtual public ClapTrap {
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
  void printStatus(void);

protected:
  bool _gateKeeperMode;
};
