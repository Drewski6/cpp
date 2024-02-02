/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/02 10:10:58 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"

int main() {
  // Constructors
  ScavTrap st("Barney");
  ScavTrap anotherST = st;

  // \n after constructors for readability
  std::cout << std::endl;

  st.guardGate();
  st.attack("random wanderer");
  st.printStatus();

  st.guardGate();
  st.guardGate();
  st.guardGate();

  // \n before destructor for readability
  std::cout << std::endl;

  return (0);
}
