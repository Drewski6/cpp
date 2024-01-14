/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:49:59 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/14 18:57:15 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>

class Zombie {
private:
  std::string name;

public:
  Zombie(std::string name_val);
  ~Zombie();

  void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif // __ZOMBIE_H__
