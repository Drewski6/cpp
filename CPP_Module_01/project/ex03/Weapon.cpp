/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:07:53 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/17 13:53:50 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"
// Static Variable Initialization

// Constructors
Weapon::Weapon(std::string type_val) : type(type_val){};

// Destructor
Weapon::~Weapon(){};

// Public Methods
const std::string &Weapon::getType(void) { return type; };

void Weapon::setType(std::string new_type) { type = new_type; };

// Private Methods
