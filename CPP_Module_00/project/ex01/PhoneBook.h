/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:19:16 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/13 13:12:59 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.h"

class PhoneBook {
private:
  int _num_contacts;
  Contact _contact_list[8];

  // Private Methods
  int get_contact_index(int num_contacts_displayed);
  int display_saved_contacts();

public:
  // Constructor
  PhoneBook(int num_contacts = 0);
  // Destructor
  ~PhoneBook();
  // Public Methods
  void search_contact();
  void edit_contact();
};

#endif // __PHONEBOOK_H__
