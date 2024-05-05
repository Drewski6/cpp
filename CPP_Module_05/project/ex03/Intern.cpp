/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:54:50 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/12 18:00:25 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Constructors , Copy Constructor, Destructor
Intern::Intern(void){};
Intern::Intern(Intern const &source) { *this = source; };
Intern::~Intern(void){};

// Overloaded Operators
Intern &Intern::operator=(Intern const &rhs) {
  if (this == &rhs)
    return (*this);
  return (*this);
};

AForm *Intern::makeForm(std::string formName, std::string targetName) const {
  AForm *newForm = NULL;
  int index = -1;
  std::string forms[3] = {"shrubbery creation", "robotomy request",
                          "presidential pardon"};

  for (int i = 0; i < 3; i++) {
    if (formName == forms[i]) {
      index = i;
      break;
    }
  }

  switch (index) {
  case (0):
    newForm = new ShrubberyCreationForm(targetName);
    std::cout << "Intern creates " << formName << " form" << std::endl;
    break;
  case (1):
    newForm = new RobotomyRequestForm(targetName);
    std::cout << "Intern creates " << formName << " form" << std::endl;
    break;
  case (2):
    newForm = new PresidentialPardonForm(targetName);
    std::cout << "Intern creates " << formName << " form" << std::endl;
    break;
  default:
    std::cout << "Intern could not make form " << formName
              << " becuase it does not exist." << std::endl;
  }
  return newForm;
};
