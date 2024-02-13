/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:13:07 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/13 13:01:58 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

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

#endif // HUMANB_H //
