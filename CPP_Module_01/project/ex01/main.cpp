/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:44:54 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/14 22:14:11 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main() {
  int num_zombies = 8;
  Zombie *horde = zombieHorde(num_zombies, "Frank");

  for (int i = 0; i < num_zombies; i++) {
    horde[i].announce();
  }

  delete[] horde;

  return (0);
}
