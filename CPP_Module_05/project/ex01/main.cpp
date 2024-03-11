/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/10 21:55:15 by dpentlan         ###   ########.fr       */
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
    // This test Initializes a Form class with bad GradeRegToSign (too high)

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
    // This test Initializes a Form class with bad GradeRegToExec (too high)

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
    // This test Initializes a Form class with bad GradeRegToSign (too low)

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
    // This test Initializes a Form class with bad GradeRegToExec (too low)

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
    std::cout << "\n===== Test 6 : beSigned Test =====\n" << std::endl;
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
  }

  return (0);
}
