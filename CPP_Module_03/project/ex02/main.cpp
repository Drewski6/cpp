/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/03 07:43:48 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"
#include "ScavTrap.h"

int main() {
  // main
  FragTrap ft1("Billy!");
  ScavTrap st1("Bobby");
  ClapTrap ct1("Jack");

  // Print status for all 3. Note they're all different.
  ft1.printStatus();
  st1.printStatus();
  ct1.printStatus();
  ft1.highFivesGuys();
  return (0);
}
