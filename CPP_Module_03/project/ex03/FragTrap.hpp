/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:13:57 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 16:40:24 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

// Adding virtual to avoid the "Diamond Problem"
class FragTrap : virtual public ClapTrap {
public:
  // Constructors , Copy Constructor, Destructor
  FragTrap(std::string name);

  FragTrap(FragTrap const &source);
  ~FragTrap(void);

  // Overloaded Operators
  FragTrap &operator=(FragTrap const &rhs);

  // Public Methods
  void highFivesGuys(void);
  void attack(const std::string &target);
  void printStatus(void);
};
