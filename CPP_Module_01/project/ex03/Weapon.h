/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:07:55 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/13 13:02:11 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

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

#endif // WEAPON_H //
