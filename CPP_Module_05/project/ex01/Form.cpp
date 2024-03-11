/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:15:11 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/10 21:53:44 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors , Copy Constructor, Destructor
Form::Form(std::string const name_val, int gradeReqToSign_val,
           int gradeReqToExec_val)
    : _name(name_val), _signedStatus(false),
      _gradeReqToSign(gradeReqToSign_val), _gradeReqToExec(gradeReqToExec_val) {
  if (_gradeReqToSign <= 0 || _gradeReqToExec <= 0)
    throw GradeTooHighException();
  if (_gradeReqToSign > 150 || _gradeReqToExec > 150)
    throw GradeTooLowException();
};

Form::Form(Form const &source)
    : _name(source._name), _signedStatus(source._signedStatus),
      _gradeReqToSign(source._gradeReqToSign),
      _gradeReqToExec(source._gradeReqToExec) {
  *this = source;
};

Form::~Form(void){};

// Overloaded Operators
Form &Form::operator=(Form const &rhs) {
  if (this == &rhs)
    return (*this);
  return (*this);
};

// Public Methods
std::string Form::getName() const { return _name; };

bool Form::getSignedStatus() const { return _signedStatus; };

int Form::getGradeReqToSign() const { return _gradeReqToSign; };

int Form::getGradeReqToExec() const { return _gradeReqToExec; };

void Form::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > _gradeReqToSign)
    throw GradeTooLowException();
  return;
};

// Exception Class Implementations
Form::GradeTooHighException::GradeTooHighException(){};
Form::GradeTooHighException::~GradeTooHighException() throw(){};
const char *Form::GradeTooHighException::what() const throw() {
  return ("Grade Too High");
}

Form::GradeTooLowException::GradeTooLowException(){};
Form::GradeTooLowException::~GradeTooLowException() throw(){};
const char *Form::GradeTooLowException::what() const throw() {
  return ("Grade Too Low");
}

// Overloaded Stream Insertion Operator
std::ostream &operator<<(std::ostream &os, const Form &f) {
  std::stringstream ss;
  ss << "========== Form Info ==========\n";
  ss << "Name               : " << f.getName() << "\n";
  ss << "Signed Status      : " << f.getSignedStatus() << "\n";
  ss << "Grade Req'd To Sign: " << f.getGradeReqToSign() << "\n";
  ss << "Grade Req'd To Exec: " << f.getGradeReqToExec() << "\n";
  os << ss.str();
  return os;
};
