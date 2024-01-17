/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:13:07 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/17 14:00:24 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_H__
#define __HUMANB_H__

#include "Weapon.h"
#include <iostream>

class HumanB {
private:
  std::string name;
  Weapon *weapon;

public:
  HumanB(std::string name_val);
  ~HumanB();
  void attack(void);
  void setWeapon(Weapon &weapon_val);
};

#endif // __HUMANB_H__
