/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/03 09:10:00 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"
#include <iostream>

int main() {
  // main
  DiamondTrap dt1("Jimbo");

  // \n so we can see the constructors more easily
  std::cout << std::endl;

  dt1.printStatus();
  dt1.attack("The Moon");
  dt1.printStatus();

  // \n so we can see the destructors more easily
  std::cout << std::endl;

  return (0);
}
