/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:34:49 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/03 15:00:20 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "FragTrap.h"
#include "ScavTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
  // Constructors , Copy Constructor, Destructor
  DiamondTrap(std::string name_val);

  DiamondTrap(DiamondTrap const &source);
  ~DiamondTrap(void);

  // Overloaded Operators
  DiamondTrap &operator=(DiamondTrap const &rhs);

  // Public Methods
  void attack(const std::string &target);
  void whoAmI(void);
  void printStatus(void);

private:
  std::string _name;
};

#endif // DIAMONDTRAP_H //
