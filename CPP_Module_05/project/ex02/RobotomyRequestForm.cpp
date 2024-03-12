/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:22:20 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/11 21:03:42 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructors , Copy Constructor, Destructor
RobotomyRequestForm::RobotomyRequestForm(std::string target_val)
    : AForm("RobotomyRequestForm", 72, 45), _target(target_val){};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &source)
    : AForm(source) {
  *this = source;
};

RobotomyRequestForm::~RobotomyRequestForm(void){};

// Overloaded Operators
RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
  if (this == &rhs)
    return (*this);
  return (*this);
};

// Public Methods
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (this->getSignedStatus() == false)
    throw FormNotSignedException();
  if (executor.getGrade() > this->getGradeReqToExec())
    throw GradeTooLowException();
  if (this->_getRandomNumber() == 1)
    std::cout << _target << " has been successfully robotomized." << std::endl;
  else
    std::cout << "I'm sorry, but the robotomy on " << _target
              << " was a failure." << std::endl;
};

// Private Methods

int RobotomyRequestForm::_getRandomNumber() const {
  std::srand(std::time(0)); // set rand seed to time.
  return std::rand() % 2;   // take % 2 of random number
};
