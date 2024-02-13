/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:49:59 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/13 13:01:14 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

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

#endif // ZOMBIE_H //
