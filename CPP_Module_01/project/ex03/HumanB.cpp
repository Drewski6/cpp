/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:13:19 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/17 14:00:51 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"
// Static Variable Initialization

// Constructors
HumanB::HumanB(std::string name_val) : name(name_val), weapon(NULL){};

// Destructor
HumanB::~HumanB(){};

// Public Methods
void HumanB::attack(void) {
  std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon_val) { weapon = &weapon_val; }

// Private Methods
