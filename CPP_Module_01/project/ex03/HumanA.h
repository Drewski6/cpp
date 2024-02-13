/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:12:46 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/13 13:01:45 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"

class HumanA {
private:
  std::string name;
  Weapon &weapon;

public:
  HumanA(std::string name_val, Weapon &weapon_val);
  ~HumanA();
  void attack(void);
};

#endif // HUMANA_H //
