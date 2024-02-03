/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:13:57 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/02 19:31:20 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : public ClapTrap {
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
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void printStatus(void);

private:
};

#endif // FRAGTRAP_H //