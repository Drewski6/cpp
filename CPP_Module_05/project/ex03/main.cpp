/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/12 18:05:04 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define GREEN "\e[32m"
#define RED "\e[31m"
#define RESET "\e[0m"

int main() {
  // Shrubbery tests

  {
    std::cout << GREEN << "===== Test 1 : Good Shrubbery Test" << RESET
              << std::endl;
    // Test Shrubbery with good parameters.

    Intern intern;
    Bureaucrat bob("Bob", 130);
    AForm *bobsForm;

    bobsForm = intern.makeForm("ShrubberyCreationForm", "Billy");
    if (bobsForm != NULL) {
      bob.signForm(*bobsForm);
      bob.executeForm(*bobsForm);

      delete bobsForm;
    }
  }

  {
    std::cout << RED << "===== Test 2 : Bad Shrubbery Test" << RESET
              << std::endl;
    // Test Shrubbery with bad parameters.

    Intern intern;
    Bureaucrat bob("Bob", 140);
    AForm *bobsForm;

    bobsForm = intern.makeForm("ShrubberyCreationForm", "Billy");
    if (bobsForm != NULL) {
      bob.signForm(*bobsForm);
      bob.executeForm(*bobsForm);

      delete bobsForm;
    }
  }

  // Robotomy Tests

  {
    std::cout << GREEN << "===== Test 3 : Good Robotomy Test" << RESET
              << std::endl;
    // Test Robotomy with good parameters.

    Intern intern;
    Bureaucrat bob("Bob", 30);
    AForm *bobsForm;

    bobsForm = intern.makeForm("RobotomyRequestForm", "Billy");
    if (bobsForm != NULL) {
      bob.signForm(*bobsForm);
      bob.executeForm(*bobsForm);

      delete bobsForm;
    }
  }

  {
    std::cout << RED << "===== Test 4 : Bad Robotomy Test" << RESET
              << std::endl;
    // Test Robotomy with bad parameters.

    Intern intern;
    Bureaucrat bob("Bob", 50);
    AForm *bobsForm;

    bobsForm = intern.makeForm("RobotomyRequestForm", "Billy");
    if (bobsForm != NULL) {
      bob.signForm(*bobsForm);
      bob.executeForm(*bobsForm);

      delete bobsForm;
    }
  }

  // Presidential Tests

  {
    std::cout << GREEN << "===== Test 5 : Good Presidential Test" << RESET
              << std::endl;
    // Test Presidential with good parameters.

    Intern intern;
    Bureaucrat bob("Bob", 30);
    AForm *bobsForm;

    bobsForm = intern.makeForm("PresidentialPardonForm", "Billy");
    if (bobsForm != NULL) {
      bob.signForm(*bobsForm);
      bob.executeForm(*bobsForm);

      delete bobsForm;
    }
  }

  {
    std::cout << RED << "===== Test 6 : Bad Presidential Test" << RESET
              << std::endl;
    // Test Presidential with bad parameters.

    Intern intern;
    Bureaucrat bob("Bob", 50);
    AForm *bobsForm;

    bobsForm = intern.makeForm("PresidentialPardonForm", "Billy");
    if (bobsForm != NULL) {
      bob.signForm(*bobsForm);
      bob.executeForm(*bobsForm);

      delete bobsForm;
    }
  }

  // Failure Tests

  {
    std::cout << RED << "===== Test 7 : Bad DoesNotExist Test" << RESET
              << std::endl;
    // Intentionally failling the interns input.

    Intern intern;
    Bureaucrat bob("Bob", 30);
    AForm *bobsForm;

    bobsForm = intern.makeForm("DoesNotExistForm", "Billy");
    if (bobsForm != NULL) {
      bob.signForm(*bobsForm);
      bob.executeForm(*bobsForm);

      delete bobsForm;
    }
  }

  return (0);
}
