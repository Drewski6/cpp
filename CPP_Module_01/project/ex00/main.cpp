/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:49:36 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/14 18:56:46 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main() {
  Zombie *my_zombie = newZombie("Joe");
  my_zombie->announce();

  randomChump("Mike");
  delete my_zombie;
  return (0);
}
