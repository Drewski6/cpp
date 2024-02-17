/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/17 17:47:39 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
  {
    std::cout << "===== Test 1 : =====" << std::endl;
    // Basic tests for most methods and constructors

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
  }

  {
    std::cout << "\n===== Test 2 : =====" << std::endl;
    // Stack allocation
    
    ScavTrap st1("Art");
    st1.attack("a defenceless chicken!");
  }

  {
    std::cout << "\n===== Test 3 : =====" << std::endl;
    // Heap allocation
    
    ScavTrap *st1 = new ScavTrap("Dork");

    st1->printStatus();
    st1->guardGate();
    st1->printStatus();

    delete st1;
  }

  return (0);
}
