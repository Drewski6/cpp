/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/17 17:53:34 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  {
    std::cout << "===== Test 1 : =====" << std::endl;
    // Basic tests for methods.

    // main
    FragTrap ft1("Billy!");
    ScavTrap st1("Bobby");
    ClapTrap ct1("Jack");

    std::cout << std::endl;

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
  }

  {
    std::cout << "\n===== Test 2 : =====" << std::endl;
    // Test
    
    FragTrap ft1("George");
    ScavTrap st1("CompleteLoner");

    std::cout << std::endl;

    ft1.beRepaired(1000);
    ft1.printStatus();

    ft1.attack("CompleteLoner");
    st1.takeDamage(30);

    std::cout << std::endl;
  }

  return (0);
}
