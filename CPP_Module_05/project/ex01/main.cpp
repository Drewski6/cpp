/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/11 09:40:57 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  {
    std::cout << "\n===== Test 1 : Good Init Form =====\n" << std::endl;
    // This test Initializes a Form class with good parameters.

    try {
      Form twenty_nine_C("29C", 29, 28);
      std::cout << twenty_nine_C << std::endl;
    } catch (const Form::GradeTooHighException &ex) {
      std::cout << ex.what() << std::endl;
    } catch (const Form::GradeTooLowException &ex) {
      std::cout << ex.what() << std::endl;
    }
  }

  {
    std::cout << "\n===== Test 2 : Bad Init Form =====\n" << std::endl;
    // This test Initializes a Form class with bad GradeReqToSign (too high)

    try {
      Form twenty_nine_C("29C", 0, 28);
      std::cout << twenty_nine_C << std::endl;
    } catch (const Form::GradeTooHighException &ex) {
      std::cout << ex.what() << std::endl;
    } catch (const Form::GradeTooLowException &ex) {
      std::cout << ex.what() << std::endl;
    }
  }

  {
    std::cout << "\n===== Test 3 : Bad Init Form =====\n" << std::endl;
    // This test Initializes a Form class with bad GradeReqToExec (too high)

    try {
      Form twenty_nine_C("29C", 29, 0);
      std::cout << twenty_nine_C << std::endl;
    } catch (const Form::GradeTooHighException &ex) {
      std::cout << ex.what() << std::endl;
    } catch (const Form::GradeTooLowException &ex) {
      std::cout << ex.what() << std::endl;
    }
  }

  {
    std::cout << "\n===== Test 4 : Bad Init Form =====\n" << std::endl;
    // This test Initializes a Form class with bad GradeReqToSign (too low)

    try {
      Form twenty_nine_C("29C", 151, 28);
      std::cout << twenty_nine_C << std::endl;
    } catch (const Form::GradeTooHighException &ex) {
      std::cout << ex.what() << std::endl;
    } catch (const Form::GradeTooLowException &ex) {
      std::cout << ex.what() << std::endl;
    }
  }

  {
    std::cout << "\n===== Test 5 : Bad Init Form =====\n" << std::endl;
    // This test Initializes a Form class with bad GradeReqToExec (too low)

    try {
      Form twenty_nine_C("29C", 29, 151);
      std::cout << twenty_nine_C << std::endl;
    } catch (const Form::GradeTooHighException &ex) {
      std::cout << ex.what() << std::endl;
    } catch (const Form::GradeTooLowException &ex) {
      std::cout << ex.what() << std::endl;
    }
  }

  {
    std::cout << "\n===== Test 6 : Good beSigned Test =====\n" << std::endl;
    // Tests Bureaucrats signing Forms

    Bureaucrat billy("Billy", 3);

    Form twenty_nine_C("29C", 3, 2);

    try {
      twenty_nine_C.beSigned(billy);
      std::cout << billy.getName() << " signed " << twenty_nine_C.getName()
                << std::endl;
    } catch (const Form::GradeTooLowException &ex) {
      std::cout << ex.what() << std::endl;
    }

    // Check status of form and ensure signed status.
    std::cout << twenty_nine_C << std::endl;
  }

  {
    std::cout << "\n===== Test 7 : Bad beSigned Test =====\n" << std::endl;
    // Tests Bureaucrats signing Forms

    Bureaucrat billy("Billy", 89);

    Form twenty_nine_C("29C", 3, 2);

    try {
      twenty_nine_C.beSigned(billy);
      std::cout << billy.getName() << " signed " << twenty_nine_C.getName()
                << std::endl;
    } catch (const Form::GradeTooLowException &ex) {
      std::cout << ex.what() << std::endl;
    }

    // Check status of form and ensure signed status.
    std::cout << twenty_nine_C << std::endl;
  }

  {
    std::cout << "\n===== Test 8 : Good Bureaucrat signForm Test =====\n"
              << std::endl;
    // This test tests the new signForm method in the Bureaucrat Class

    Bureaucrat jonny("Jonny", 21);

    Form thirty_three("Form33", 45, 41);

    jonny.signForm(thirty_three);

    // Check status of form and ensure signed status.
    std::cout << thirty_three << std::endl;
  }

  {
    std::cout
        << "\n===== Test 9 : Another Good Bureaucrat signForm Test =====\n"
        << std::endl;
    // This test tests the new signForm method in the Bureaucrat Class

    Bureaucrat mr_bill("Mr.Bill", 45);

    Form forty_five("Form45", 45, 41);

    mr_bill.signForm(forty_five);

    // Check status of form and ensure signed status.
    std::cout << forty_five << std::endl;
  }

  {
    std::cout << "\n===== Test 10 : Bad Bureaucrat signForm Test =====\n"
              << std::endl;
    // This test tests the new signForm method in the Bureaucrat Class

    Bureaucrat juan("Juan", 50);

    Form forty_five("Form45", 45, 41);

    juan.signForm(forty_five);

    // Check status of form and ensure signed status.
    std::cout << forty_five << std::endl;
  }

  return (0);
}
