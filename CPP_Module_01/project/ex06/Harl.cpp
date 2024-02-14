/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:00:35 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/14 22:33:01 by dpentlan         ###   ########.fr       */
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
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  int i = 0;

  while (i < 4) {
    if (level == levels[i])
      break;
    i++;
  }

  // Switch is required by subject but with -std-c++98 -Wall -Wextra -Werror and
  // no break; statement, we will always get a compiler warning, which will not
  // compiler with the -Werror flag. Best solution I could find is to add
  // incrementors
  switch (i) {
  case 0:
    (this->*ptrs[i++])();
    (this->*ptrs[i++])();
    (this->*ptrs[i++])();
    (this->*ptrs[i])();
    break;
  case 1:
    (this->*ptrs[i++])();
    (this->*ptrs[i++])();
    (this->*ptrs[i])();
    break;
  case 2:
    (this->*ptrs[i++])();
    (this->*ptrs[i])();
    break;
  case 3:
    (this->*ptrs[i])();
    break;
  default:
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
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
