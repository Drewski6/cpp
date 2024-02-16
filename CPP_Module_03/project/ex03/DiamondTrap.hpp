/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 08:34:49 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 17:53:29 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
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
