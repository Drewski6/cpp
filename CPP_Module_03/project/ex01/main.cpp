/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/03 08:25:02 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

int main() {
  // Constructors
  ScavTrap st1("Barney");
  ScavTrap st2 = st1;
  ClapTrap cp1("Johanne");

  // \n after constructors for readability
  std::cout << std::endl;

  st1.guardGate();
  // Note different attack strings for ScavTrap and ClapTrap
  st1.attack("random wanderer");
  cp1.attack("another poor wanderer");

  // Inherited methods
  st1.takeDamage(1);
  st1.beRepaired(1);
  st1.printStatus();

  // Take damage and check if able to act.
  st1.takeDamage(100);
  st1.attack("poor wanderer");

  // \n before destructor for readability
  std::cout << std::endl;

  return (0);
}
