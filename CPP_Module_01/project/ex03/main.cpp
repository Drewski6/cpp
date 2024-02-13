/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:07:07 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/13 15:45:19 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"
#include "HumanB.h"
#include "Weapon.h"
#include <iostream>

int main() {
  {
    std::cout << "===== Test 1 =====" << std::endl;
    // Example from subject
    {
      Weapon club = Weapon("crude spiked club");
      HumanA bob("Bob", club);
      bob.attack();
      club.setType("some other type of club");
      bob.attack();
    }
    {
      Weapon club = Weapon("crude spiked club");
      HumanB jim("Jim");
      jim.setWeapon(club);
      jim.attack();
      club.setType("some other type of club");
      jim.attack();
    }
  }

  {
    std::cout << "\n===== Test 2 =====" << std::endl;
    // Example using pointers
    Weapon *bb = new Weapon("Baseball bat");
    if (bb == NULL)
      return (1);
    HumanA billy("Billy", *bb);
    billy.attack();

    delete bb;
  }

  return 0;
}
