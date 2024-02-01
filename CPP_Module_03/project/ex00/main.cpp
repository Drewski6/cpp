/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/01 13:57:47 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include <iostream>

int main() {
  {
    std::cout << "Testing Copy Constructor" << std::endl;
    ClapTrap test1("ImATest");
    ClapTrap test2 = test1;
    test1.printStatus();
    test2.printStatus();
  }
  std::cout << std::endl;
  // Start
  ClapTrap b1("Bruno");
  ClapTrap h1("Hans");

  // Starting
  std::cout << "\nPrint Starting Status: " << std::endl;
  b1.printStatus();
  h1.printStatus();

  // 1. Damage example
  std::cout << "\nExample 1: " << std::endl;
  b1.takeDamage(9);
  b1.printStatus();

  // 2. Repair example
  std::cout << "\nExample 2: " << std::endl;
  b1.beRepaired(1);
  b1.printStatus();

  // 3. Attack example
  std::cout << "\nExample 3: " << std::endl;
  b1.attack("Hans");
  h1.takeDamage(0);
  b1.printStatus();
  h1.printStatus();

  // 4. Damage example when hp is 0
  std::cout << "\nExample 4: " << std::endl;
  b1.takeDamage(2);
  b1.printStatus();

  // 5. Repair example when hp is 0
  std::cout << "\nExample 5: " << std::endl;
  b1.beRepaired(1);
  b1.printStatus();

  // 6. Attack example when hp is 0
  std::cout << "\nExample 6: " << std::endl;
  b1.attack("Hans");
  b1.printStatus();

  // 7. Have Hans use all his energy
  std::cout << "\nExample 7: " << std::endl;
  for (int i = 0; i < 10; i++)
    h1.beRepaired(0);
  // Try to attack with 0 energy
  h1.attack("Bruno");
  h1.printStatus();

  // 8. Take damage and try to heal with 0 energy.
  std::cout << "\nExample 8: " << std::endl;
  h1.takeDamage(4);
  h1.beRepaired(1);
  h1.printStatus();

  std::cout << std::endl;
  return (0);
}
