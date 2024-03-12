/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:21:46 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/11 19:29:16 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
public:
  // Constructors , Copy Constructor, Destructor
  PresidentialPardonForm(std::string target_val);
  PresidentialPardonForm(PresidentialPardonForm const &source);
  ~PresidentialPardonForm(void);

  // Overloaded Operators
  PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

  // Public Methods
  void execute(Bureaucrat const &executor) const;

private:
  std::string const _target;
};
