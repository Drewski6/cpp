/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:07:55 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/17 13:45:01 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>

class Weapon {
private:
  std::string type;

public:
  // Constructor
  Weapon(std::string type = "None");

  // Destructor
  ~Weapon();

  // Getters
  const std::string &getType(void);

  // Setters
  void setType(std::string new_type);
};

#endif // __WEAPON_H__
