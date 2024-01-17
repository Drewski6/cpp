/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:12:46 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/17 13:54:46 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_H__
#define __HUMANA_H__

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

#endif // __HUMANA_H__
