/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:44:54 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/13 14:57:51 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>

int main() {

  {
    std::cout << "===== Test 1 =====" << std::endl;
    // Basic test that follows the subject
    int num_zombies = 8;
    Zombie *horde = zombieHorde(num_zombies, "Frank");

    for (int i = 0; i < num_zombies; i++) {
      horde[i].announce();
    }

    delete[] horde;
  }

  return (0);
}
