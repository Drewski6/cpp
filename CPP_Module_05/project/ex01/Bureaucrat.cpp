/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 01:52:13 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/11 09:32:21 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors , Copy Constructor, Destructor
Bureaucrat::Bureaucrat(const std::string name_val, int grade_val)
    : _name(name_val), _grade(grade_val) {
  if (_grade <= 0)
    throw GradeTooHighException();
  if (_grade > 150)
    throw GradeTooLowException();
};

Bureaucrat::Bureaucrat(Bureaucrat const &source) { *this = source; };
Bureaucrat::~Bureaucrat(void){};

// Overloaded Operators
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};

// Public Methods
std::string Bureaucrat::getName(void) const { return (_name); };

int Bureaucrat::getGrade(void) const { return (_grade); };

void Bureaucrat::incGrade(void) {
  if (_grade - 1 <= 0)
    throw GradeTooHighException();
  _grade = _grade - 1;
};

void Bureaucrat::decGrade(void) {
  if (_grade + 1 > 150)
    throw GradeTooLowException();
  _grade = _grade + 1;
};

void Bureaucrat::signForm(Form &f) {
  (void)f;
  try {
    f.beSigned(*this);
    std::cout << this->getName() << " signed " << f.getName() << std::endl;
  } catch (const Form::GradeTooLowException &ex) {
    std::cout << this->getName() << " couldn't sign " << f.getName()
              << " because " << ex.what() << std::endl;
  }
};

// Exception Class Implementations
Bureaucrat::GradeTooHighException::GradeTooHighException(){};
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw(){};
const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade Too High");
}

Bureaucrat::GradeTooLowException::GradeTooLowException(){};
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw(){};
const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade Too Low");
}

// Overloaded Stream Insertion Operator
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
  std::stringstream ss;
  ss << b.getName() << ", bureaucrat grade " << b.getGrade();
  os << ss.str();
  return os;
};
