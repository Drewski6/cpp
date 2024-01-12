/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:18:18 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/11 18:13:32 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <iostream>

void startup_prompt() {
  std::cout << "=== Phone Book ===" << std::endl;
  std::cout << "\nThis program is capable of storing up to 8 entire contacts!"
            << std::endl;
  std::cout << "To use, enter the command you'd like to perform:" << std::endl;
  std::cout << "\tADD:    Add a new contact." << std::endl;
  std::cout << "\tSEARCH: Search through saved contacts." << std::endl;
  std::cout << "\tEXIT:   Safely exit the program and lose all your data."
            << std::endl;
}

int main() {
  PhoneBook phonebook;
  std::string usr_input("");

  startup_prompt();
  while (usr_input != "EXIT") {
    std::getline(std::cin, usr_input);
    if (usr_input == "SEARCH") {
      phonebook.search_contact();
    } else if (usr_input == "ADD") {
      phonebook.edit_contact();
    } else if (usr_input != "EXIT") {
      std::cout << "No such command: Please enter 'ADD', 'SEARCH', or 'EXIT'"
                << std::endl;
    }
  }

  return (0);
}
