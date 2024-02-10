/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:19:37 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/10 14:31:27 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <iostream>
#include <sstream>

// Constructors
PhoneBook::PhoneBook(int num_contacts_val) : _num_contacts(num_contacts_val){};

// Destructor
PhoneBook::~PhoneBook(){};

// Public Methods
void PhoneBook::search_contact() {
  int index = 0;
  int num_contacts_displayed = 0;

  num_contacts_displayed = display_saved_contacts();
  if (num_contacts_displayed != 0) {
    index = get_contact_index(num_contacts_displayed);
    _contact_list[index].display_contact_full();
  }
}

void PhoneBook::edit_contact() {
  std::string new_first_name;
  std::string new_last_name;
  std::string new_nickname;
  std::string new_phone_number;
  std::string new_darkest_secret;

  requestContactInfo(new_first_name, "first name");
  requestContactInfo(new_last_name, "last name");
  requestContactInfo(new_nickname, "nickname");
  requestContactInfo(new_phone_number, "phone number");
  requestContactInfo(new_darkest_secret, "darkest secret");

  _contact_list[_num_contacts % 8].set_first_name(new_first_name);
  _contact_list[_num_contacts % 8].set_last_name(new_last_name);
  _contact_list[_num_contacts % 8].set_nickname(new_nickname);
  _contact_list[_num_contacts % 8].set_phone_number(new_phone_number);
  _contact_list[_num_contacts % 8].set_darkest_secret(new_darkest_secret);
  _contact_list[_num_contacts % 8].set_saved_contact(true);
  ++_num_contacts;
  std::cout << "New contact successfully added." << std::endl;
}

// Private Methods
int PhoneBook::display_saved_contacts() {
  int num_contacts_displayed = 0;

  for (int i = 0; i < 8; i++) {
    if (_contact_list[i].get_saved_contact() == true) {
      _contact_list[i].display_contact_abrv(i);
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
    iss >> usr_num; // Convert input from player to int.
    if (usr_num <= 0 ||
        usr_num > num_contacts_displayed) // if input not int, retry.
      std::cout << "Invalid input, please enter an index from the list shown"
                << std::endl;
  }
  return (usr_num - 1);
}

void PhoneBook::requestContactInfo(std::string &contactItem,
                                   const std::string contactItemLabel) {
  std::cout << "Enter the " << contactItemLabel
            << " of your new contact: " << std::endl;
  std::getline(std::cin, contactItem);
  while (contactItem.length() == 0 || containsOnlyWhitespace(contactItem)) {
    std::cout << "Field cannot be left empty." << std::endl;
    std::cout << "Enter the " << contactItemLabel
              << " of your new contact: " << std::endl;
    std::getline(std::cin, contactItem);
  }
}

bool PhoneBook::containsOnlyWhitespace(const std::string &str) {
  // Checks input str for any non-whitespace character.
  return str.find_first_not_of(" \t\n\v\f\r") == std::string::npos;
}
