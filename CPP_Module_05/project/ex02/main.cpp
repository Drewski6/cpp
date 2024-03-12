/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/11 20:41:12 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define GREEN "\e[32m"
#define RED "\e[31m"
#define RESET "\e[0m"

int main() {

  // ************************ ShrubberyCreationForm ********************* //

  {
    std::cout
        << GREEN
        << "\n===== Test 1 : Good ShrubberyCreationForm executeForm =====\n"
        << RESET << std::endl;
    // Tests the executeForm for Bureaucrat (Grade high enough to sign and exec)

    Bureaucrat billy("Billy", 120);
    ShrubberyCreationForm shrub1("Bobby");

    std::cout << billy << std::endl;
    billy.signForm(shrub1);
    billy.executeForm(shrub1);
    std::cout << "\n" << shrub1 << std::endl;
  }

  {
    std::cout
        << RED
        << "\n===== Test 2 : Bad ShrubberyCreationForm executeForm =====\n"
        << RESET << std::endl;
    // Tests the executeForm for Bureaucrat (Grade too low to execute)

    Bureaucrat bonk("Bonk", 140);
    ShrubberyCreationForm shrub2("Bobby");

    std::cout << bonk << std::endl;
    bonk.signForm(shrub2);
    bonk.executeForm(shrub2);
    std::cout << "\n" << shrub2 << std::endl;
  }

  {
    std::cout
        << RED
        << "\n===== Test 3 : Bad ShrubberyCreationForm sign and exec =====\n "
        << RESET << std::endl;
    // Tests the executeForm for Bureaucrat (Grade too low to sign)

    Bureaucrat bob("Bob", 150);
    ShrubberyCreationForm shrub3("Bobby");

    std::cout << bob << std::endl;
    bob.signForm(shrub3);
    bob.executeForm(shrub3);
    std::cout << "\n" << shrub3 << std::endl;
  }

  // ************************ RobotomyRequestForm ********************* //

  {
    std::cout
        << GREEN
        << "\n===== Test 4 : Good RobotomyRequestForm executeForm =====\n "
        << RESET << std::endl;
    // Tests the executeForm for Bureaucrat (Grade high enough to sign and exec)

    Bureaucrat billy("Billy", 33);
    RobotomyRequestForm robotomy1("Bobby");

    std::cout << billy << std::endl;
    billy.signForm(robotomy1);
    billy.executeForm(robotomy1);
    std::cout << "\n" << robotomy1 << std::endl;
  }

  {
    std::cout << RED
              << "\n===== Test 5 : Bad RobotomyRequestForm executeForm =====\n "
              << RESET << std::endl;
    // Tests the executeForm for Bureaucrat (Grade too low to execute)

    Bureaucrat bonk("Bonk", 50);
    RobotomyRequestForm robotomy2("Bobby");

    std::cout << bonk << std::endl;
    bonk.signForm(robotomy2);
    bonk.executeForm(robotomy2);
    std::cout << "\n" << robotomy2 << std::endl;
  }

  {
    std::cout
        << RED
        << "\n===== Test 6 : Bad PresidentialPardonForm sign and exec =====\n"
        << RESET << std::endl;
    // Tests the executeForm for Bureaucrat (Grade too low to sign)

    Bureaucrat bob("Bob", 80);
    RobotomyRequestForm robotomy3("Bobby");

    std::cout << bob << std::endl;
    bob.signForm(robotomy3);
    bob.executeForm(robotomy3);
    std::cout << "\n" << robotomy3 << std::endl;
  }

  // ************************ PresidentialPardonForm ********************* //

  {
    std::cout
        << GREEN
        << "\n===== Test 7 : Good PresidentialPardonForm executeForm =====\n"
        << RESET << std::endl;
    // Tests the executeForm for Bureaucrat (Grade high enough to sign and exec)
    Bureaucrat billy("Billy", 3);
    PresidentialPardonForm pardon1("Bobby");

    std::cout << billy << std::endl;
    billy.signForm(pardon1);
    billy.executeForm(pardon1);
    std::cout << "\n" << pardon1 << std::endl;
  }

  {
    std::cout
        << RED
        << "\n===== Test 8 : Bad PresidentialPardonForm executeForm =====\n"
        << RESET << std::endl;
    // Tests the executeForm for Bureaucrat (Grade too low to execute)

    Bureaucrat bonk("Bonk", 9);
    PresidentialPardonForm pardon2("Bobby");

    std::cout << bonk << std::endl;
    bonk.signForm(pardon2);
    bonk.executeForm(pardon2);
    std::cout << "\n" << pardon2 << std::endl;
  }

  {
    std::cout
        << RED
        << "\n===== Test 9 : Bad PresidentialPardonForm sign and exec =====\n"
        << RESET << std::endl;
    // Tests the executeForm for Bureaucrat (Grade too low to sign)

    Bureaucrat bob("Bob", 28);
    PresidentialPardonForm pardon3("Bobby");

    std::cout << bob << std::endl;
    bob.signForm(pardon3);
    bob.executeForm(pardon3);
    std::cout << "\n" << pardon3 << std::endl;
  }

  return (0);
}
