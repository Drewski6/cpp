/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:49:36 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/13 13:27:02 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>

int main() {
  std::cout << "\n===== Test 1 =====" << std::endl;

  {
    // Test of allocation on the heap and using associated functions.
    Zombie *my_zombie = newZombie("Joe");
    my_zombie->announce();

    randomChump("Mike");
    delete my_zombie;
  }

  std::cout << "\n===== Test 2 =====" << std::endl;

  {
    // Test of allocation on the heap
    Zombie *a_zombie = new Zombie("Bob");
    a_zombie->announce();

    delete a_zombie;
  }

  std::cout << "\n===== Test 3 =====" << std::endl;

  {
    // Test of creation on the stack
    Zombie new_zombie = Zombie("My_Name_Is_Local_Scope");
    new_zombie.announce();
  }

  return (0);
}
