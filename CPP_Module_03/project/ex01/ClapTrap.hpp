/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:13 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 15:58:04 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap {
public:
  // Constructors , Copy Constructor, Destructor
  ClapTrap(std::string name);

  ClapTrap(ClapTrap const &source);
  ~ClapTrap(void);

  // Overloaded Operators
  ClapTrap &operator=(ClapTrap const &rhs);

  // Public Methods
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  void printStatus(void); // For making evaluation easier. :)

protected:
  std::string _name;
  int _hp;
  int _ep;
  int _atk;

  // Private Methods
  bool _useEnergy(int amount);
  bool _energyCheck(int amount);
  bool _healthCheck(int amount);
};
