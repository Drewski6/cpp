/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:49:49 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/14 21:17:50 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

// Constructors
Zombie::Zombie() : name("None"){};
Zombie::Zombie(std::string name_val) : name(name_val){};

// Destructor
Zombie::~Zombie() {
  std::cout << "Zombie named " << name << " has died." << std::endl;
}

// Public Methods
void Zombie::announce(void) {
  std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Private Methods
