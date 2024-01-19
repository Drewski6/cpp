/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:00:35 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/19 20:55:07 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"
// Static Variable Initialization

// Constructors
Harl::Harl(){};

// Destructor
Harl::~Harl(){};

// Public Methods
void Harl::complain(std::string level) {
  fPtr ptrs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
  std::string levels[4] = {"debug", "info", "warning", "error"};
  int i = 0;

  while (i < 4) {
    if (level == levels[i])
      break;
    i++;
  }

  if (i == 4) {
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
  }

  while (i < 4) {
    (this->*ptrs[i])();
    i++;
  }
};

// Private Methods
void Harl::debug(void) {
  std::cout << "[ DEBUG ]\n"
            << "I love having extra bacon for my "
               "7XL-double-cheese-triple-pickle-special-ketchup burger. I "
               "really do!\n"
            << std::endl;
};

void Harl::info(void) {
  std::cout
      << "[ INFO ]\n"
      << "I cannot believe adding extra bacon costs more money. You "
         "didn’t put enough bacon in my burger! If you did, I wouldn’t be "
         "asking for more!\n"
      << std::endl;
};

void Harl::warning(void) {
  std::cout
      << "[ WARNING ]\n"
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years whereas you started working here since last month.\n"
      << std::endl;
};

void Harl::error(void) {
  std::cout << "[ ERROR ]\n"
            << "This is unacceptable! I want to speak to the manager now.\n"
            << std::endl;
};
