/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:49:59 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/14 22:17:20 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>

class Zombie {
private:
  std::string name;

public:
  Zombie(std::string name_val = "None");
  ~Zombie();

  void announce(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif // __ZOMBIE_H__
