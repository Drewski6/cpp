/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:49:59 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/14 21:17:57 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
private:
  std::string name;

public:
  Zombie();
  Zombie(std::string name_val);
  ~Zombie();

  void announce(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif // ZOMBIE_H //
