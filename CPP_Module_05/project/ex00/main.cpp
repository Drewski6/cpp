/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:06:08 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/10 10:35:21 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main() {
  {
    std::cout << "\n===== Test 1: Good Init - Grade too high =====\n" << std::endl;
    // This test Initializes a Bureaucrat correctly but then attempts to 
    // increment it's grade past the max allowed grade.
    // Also tests the incGrade method.

    Bureaucrat billy("Billy", 2);

    std::cout << billy << std::endl;

    billy.incGrade();       // increase from 2 to 1 (highest)

    std::cout << billy << std::endl;

    try {
      billy.incGrade();     // increase from 1 to 0 (too high)
    } catch (const Bureaucrat::GradeTooHighException &ex) {
      std::cout << ex.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &ex) {
      std::cout << ex.what() << std::endl;
    }
  }

  {
    std::cout << "\n===== Test 2: Good Init - Grade too low =====\n" << std::endl;
    // This test Initializes a Bureaucrat correctly but then attempts to 
    // decrement it's grade past the min allowed grade.
    // Also tests the decGrade method.

    Bureaucrat billy("Billy", 149);

    std::cout << billy << std::endl;

    billy.decGrade();       // dec from 149 to 150 (lowest)

    std::cout << billy << std::endl;

    try {
      billy.decGrade();     // dec from 150 to 151 (too low)
    } catch (const Bureaucrat::GradeTooHighException &ex) {
      std::cout << ex.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &ex) {
      std::cout << ex.what() << std::endl;
    }
  }

  {
    std::cout << "\n===== Test 3 : Bad Init - Grade too high =====\n" << std::endl;
    // This test Initializes a Bureaucrat with too high of a grade.

    try {
      Bureaucrat test("Bobby", -1);
    } catch (const Bureaucrat::GradeTooHighException &ex) {
      std::cout << ex.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &ex) {
      std::cout << ex.what() << std::endl;
    }
  }
  
  {
    std::cout << "\n===== Test 4 : Bad Init - Grade too low =====\n" << std::endl;
    // This test Initializes a Bureaucrat with too low of a grade.

    try {
      Bureaucrat test("Bobby", 159);
    } catch (const Bureaucrat::GradeTooHighException &ex) {
      std::cout << ex.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException &ex) {
      std::cout << ex.what() << std::endl;
    }
  }

  return (0);
}
