/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 16:59:43 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main() {
  {
    std::cout << "===== Testing Copy Constructor =====" << std::endl;
    ClapTrap test1("ImATest");
    ClapTrap test2 = test1;
    test1.printStatus();
    test2.printStatus();
  }

  {
    std::cout << std::endl;
    // Start
    ClapTrap bruno("Bruno");
    ClapTrap hans("Hans");

    std::cout << "===== Print Starting Status: =====" << std::endl;
    // Starting
    bruno.printStatus();
    hans.printStatus();

    std::cout << "===== Example 1: =====" << std::endl;
    // 1. Damage example
    bruno.takeDamage(9);
    bruno.printStatus();

    std::cout << "===== Example 2: =====" << std::endl;
    // 2. Repair example
    bruno.beRepaired(1);
    bruno.printStatus();

    std::cout << "===== Example 3: =====" << std::endl;
    // 3. Attack example
    bruno.attack("Hans");
    hans.takeDamage(0);
    bruno.printStatus();
    hans.printStatus();

    std::cout << "===== Example 4: =====" << std::endl;
    // 4. Damage example when hp is 0
    bruno.takeDamage(2);
    bruno.printStatus();

    std::cout << "===== Example 5: =====" << std::endl;
    // 5. Repair example when hp is 0
    bruno.beRepaired(1);
    bruno.printStatus();

    std::cout << "===== Example 6: =====" << std::endl;
    // 6. Attack example when hp is 0
    bruno.attack("Hans");
    bruno.printStatus();

    std::cout << "===== Example 7: =====" << std::endl;
    // 7. Have Hans use all his energy
    for (int i = 0; i < 10; i++)
      hans.beRepaired(0);
    // Try to attack with 0 energy
    hans.attack("Bruno");
    hans.printStatus();

    std::cout << "===== Example 8: =====" << std::endl;
    // 8. Take damage and try to heal with 0 energy.
    hans.takeDamage(4);
    hans.beRepaired(1);
    hans.printStatus();

    std::cout << std::endl;
  }

  return (0);
}
