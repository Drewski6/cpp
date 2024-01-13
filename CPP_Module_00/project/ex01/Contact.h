/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:18:26 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/13 10:03:01 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>

class Contact {
private:
  bool saved_contact;
  std::string first_name;
  std::string last_name;
  std::string nickname;
  std::string phone_number;
  std::string darkest_secret;

public:
  // CONSTRUCTOR
  Contact(bool saved_contact = false, std::string first_name = "None",
          std::string last_name = "None", std::string nickname = "None",
          std::string phone_number = "None",
          std::string darkest_secret = "None");
  ~Contact();

  // Public Methods
  void display_contact_abrv(int index);
  void display_contact_full(void);

  // GETTERS
  bool get_saved_contact();

  // SETTERS
  void set_first_name(std::string first_name_val);
  void set_last_name(std::string last_name_val);
  void set_nickname(std::string nickname_val);
  void set_phone_number(std::string phone_number_val);
  void set_darkest_secret(std::string darkest_secret_val);
  void set_saved_contact(bool saved_contact_val);
};

#endif // __CONTACT_H__
