/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:12:59 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/17 13:36:25 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"
#include "Weapon.h"
#include <iostream>

// Static Variable Initialization

// Constructors
HumanA::HumanA(std::string name_val, Weapon &weapon_val)
    : name(name_val), weapon(weapon_val){};

// Destructor
HumanA::~HumanA(){};

// Public Methods
void HumanA::attack(void) {
  std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

// Private Methods
