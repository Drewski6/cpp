/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:19:37 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/12 15:54:28 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <iostream>
#include <sstream>

// Constructors
PhoneBook::PhoneBook(int num_contacts_val) : num_contacts(num_contacts_val){};

// Destructor
PhoneBook::~PhoneBook(){};

// Public Methods
void PhoneBook::search_contact() {
  int index = 0;
  int num_contacts_displayed = 0;

  num_contacts_displayed = display_saved_contacts();
  std::cout << "num_contacts_displayed: " << num_contacts_displayed
            << std::endl;
  if (num_contacts_displayed != 0) {
    index = get_contact_index(num_contacts_displayed);
    contact_list[index].display_contact_full(index);
  }
}

void PhoneBook::edit_contact() {
  std::string new_first_name;
  std::string new_last_name;
  std::string new_nickname;
  std::string new_phone_number;
  std::string new_darkest_secret;
  std::cout << "Enter the first name of your new contact: " << std::endl;
  std::getline(std::cin, new_first_name);
  if (new_first_name.length() == 0) {
    std::cout << "Field cannot be left empty. Returning to main." << std::endl;
    return;
  }
  std::cout << "Enter the last name of your new contact: " << std::endl;
  std::getline(std::cin, new_last_name);
  if (new_last_name.length() == 0) {
    std::cout << "Field cannot be left empty. Returning to main." << std::endl;
    return;
  }
  std::cout << "Enter the nickname of your new contact: " << std::endl;
  std::getline(std::cin, new_nickname);
  if (new_nickname.length() == 0) {
    std::cout << "Field cannot be left empty. Returning to main." << std::endl;
    return;
  }
  std::cout << "Enter the phone number of your new contact: " << std::endl;
  std::getline(std::cin, new_phone_number);
  if (new_phone_number.length() == 0) {
    std::cout << "Field cannot be left empty. Returning to main." << std::endl;
    return;
  }
  std::cout << "Enter the darkest secret of your new contact: " << std::endl;
  std::getline(std::cin, new_darkest_secret);
  if (new_darkest_secret.length() == 0) {
    std::cout << "Field cannot be left empty. Returning to main." << std::endl;
    return;
  }
  contact_list[num_contacts % 8].set_first_name(new_first_name);
  contact_list[num_contacts % 8].set_last_name(new_last_name);
  contact_list[num_contacts % 8].set_nickname(new_nickname);
  contact_list[num_contacts % 8].set_phone_number(new_phone_number);
  contact_list[num_contacts % 8].set_darkest_secret(new_darkest_secret);
  contact_list[num_contacts % 8].set_saved_contact(true);
  ++num_contacts;
  std::cout << "New contact successfully added." << std::endl;
}

// Private Methods
int PhoneBook::display_saved_contacts() {
  int num_contacts_displayed = 0;

  for (int i = 0; i < 8; i++) {
    if (contact_list[i].get_saved_contact() == true) {
      contact_list[i].display_contact_abrv(i);
      num_contacts_displayed++;
    }
  }
  if (num_contacts_displayed == 0)
    std::cout << "No contacts to display." << std::endl;
  return num_contacts_displayed;
}

int PhoneBook::get_contact_index(int num_contacts_displayed) {
  std::string usr_input = "";
  int usr_num = -1;

  std::cout
      << "Please select a contact to display by entering its index number: "
      << std::endl;
  while (usr_num <= 0 || usr_num > num_contacts_displayed) {
    std::getline(std::cin, usr_input);
    std::istringstream iss(usr_input);
    iss >> usr_num;
    if (usr_num <= 0 || usr_num > num_contacts_displayed)
      std::cout << "Invalid input, please enter an index from the list shown"
                << std::endl;
  }
  return (usr_num - 1);
}
