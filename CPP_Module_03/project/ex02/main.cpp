/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 16:05:49 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  // main
  FragTrap ft1("Billy!");
  ScavTrap st1("Bobby");
  ClapTrap ct1("Jack");

  // Print status for all 3. Note they're all different.
  ft1.printStatus();
  st1.printStatus();
  ct1.printStatus();

  // High Five test
  ft1.highFivesGuys();

  // Test Inherited methods
  ft1.takeDamage(10);
  ft1.beRepaired(5);
  ft1.printStatus();

  return (0);
}
