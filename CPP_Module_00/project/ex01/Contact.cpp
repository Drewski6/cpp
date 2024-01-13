/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:19:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/13 10:07:37 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

#include <iomanip>
#include <iostream>
#include <string>

// Constructors
Contact::Contact(bool saved_contact_val, std::string first_name_val,
                 std::string last_name_val, std::string nickname_val,
                 std::string phone_number_val, std::string darkest_secret_val)
    : saved_contact(saved_contact_val), first_name(first_name_val),
      last_name(last_name_val), nickname(nickname_val),
      phone_number(phone_number_val), darkest_secret(darkest_secret_val){};

// Destructor
Contact::~Contact(){};

// Public Member Functions (Public Methods)
void Contact::display_contact_abrv(int index) {
  std::cout << std::setw(10) << (index + 1) << "|";
  if (first_name.length() > 10)
    std::cout << first_name.substr(0, 9) << ".|";
  else
    std::cout << std::setw(10) << first_name << "|";
  if (last_name.length() > 10)
    std::cout << last_name.substr(0, 9) << ".|";
  else
    std::cout << std::setw(10) << last_name << "|";
  if (nickname.length() > 10)
    std::cout << nickname.substr(0, 9) << "." << std::endl;
  else
    std::cout << std::setw(10) << nickname << std::endl;
}

void Contact::display_contact_full(void) {
  std::cout << "First Name    : " << first_name << std::endl;
  std::cout << "Last Name     : " << last_name << std::endl;
  std::cout << "Nickname      : " << nickname << std::endl;
  std::cout << "Phone Number  : " << phone_number << std::endl;
  std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}
// GETTERS
bool Contact::get_saved_contact() { return saved_contact; };

// SETTERS
void Contact::set_first_name(std::string first_name_val) {
  first_name = first_name_val;
}

void Contact::set_last_name(std::string last_name_val) {
  last_name = last_name_val;
}

void Contact::set_nickname(std::string nickname_val) {
  nickname = nickname_val;
}

void Contact::set_phone_number(std::string phone_number_val) {
  phone_number = phone_number_val;
}

void Contact::set_darkest_secret(std::string darkest_secret_val) {
  darkest_secret = darkest_secret_val;
}

void Contact::set_saved_contact(bool saved_contact_val) {
  saved_contact = saved_contact_val;
}

// Private Member Functions (Private Methods)
