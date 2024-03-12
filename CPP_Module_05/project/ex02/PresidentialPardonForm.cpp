/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:21:30 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/11 18:38:33 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors , Copy Constructor, Destructor
PresidentialPardonForm::PresidentialPardonForm(std::string target_val)
    : AForm("PresidentialPardonForm", 25, 5), _target(target_val){};

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &source)
    : AForm(source) {
  *this = source;
};

PresidentialPardonForm::~PresidentialPardonForm(void){};

// Overloaded Operators
PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
  if (this == &rhs)
    return (*this);
  return (*this);
};

// Public Methods
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (this->getSignedStatus() == false)
    throw FormNotSignedException();
  if (executor.getGrade() > this->getGradeReqToExec())
    throw GradeTooLowException();
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
};
