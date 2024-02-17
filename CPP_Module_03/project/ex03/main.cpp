/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/17 17:55:53 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main() {
  {
    std::cout << "\n===== Test 1 : =====" << std::endl;
    // Basic constructors and print status tests to see that everything has the right starting stats.
    
    ClapTrap ct1("Number One Dad");
    ScavTrap st1("Megan");
    FragTrap ft1("Big Foot");
    DiamondTrap dt1("Jimbo");

    // \n so we can see the constructors more easily
    std::cout << std::endl;

    ct1.printStatus();
    st1.printStatus();
    ft1.printStatus();
    dt1.printStatus();
  }

  {
    std::cout << "\n===== Test 2 : =====" << std::endl;
    // WhoAmI test

    DiamondTrap dt1("Jim Bob");
    // \n so we can see the constructors more easily
    std::cout << std::endl;

    dt1.whoAmI();

    // \n so we can see the destructors more easily
    std::cout << std::endl;
  }

  {
    std::cout << "\n===== Test 3 : =====" << std::endl;
    // testing inherited methods

    DiamondTrap dt1("Angela");
    // \n so we can see the constructors more easily
    std::cout << std::endl;

    // ScavTrap attack
    dt1.attack("Michael");
    // FragTrap high five method
    dt1.highFivesGuys();
    // ScavTrap guard gate method
    dt1.guardGate();

    // \n so we can see the destructors more easily
    std::cout << std::endl;
  }

  return (0);
}
