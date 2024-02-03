/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/03 15:02:40 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "DiamondTrap.h"
#include <iostream>

int main() {
  {
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

  std::cout << std::endl;
  std::cout << "=============================================" << std::endl;
  std::cout << std::endl;

  {
    DiamondTrap dt1("Jim Bob");
    // \n so we can see the constructors more easily
    std::cout << std::endl;

    dt1.whoAmI();

    // \n so we can see the destructors more easily
    std::cout << std::endl;
  }

  std::cout << std::endl;
  std::cout << "=============================================" << std::endl;
  std::cout << std::endl;

  {
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
