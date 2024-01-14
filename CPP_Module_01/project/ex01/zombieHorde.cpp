/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:53:49 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/14 22:13:53 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

/*
 *  Using 2 new calls.
 *    First: Classic allocation for an array of Zombie objects.
 *    Second: special new call called 'placement new' which takes a reference to
 * the memory location where the constructed object will be placed.
 */

Zombie *zombieHorde(int N, std::string name) {
  Zombie *zombie_horde = new Zombie[N];

  for (int i = 0; i < N; i++) {
    new (&zombie_horde[i]) Zombie(name); // placement new
  }

  return zombie_horde;
}
