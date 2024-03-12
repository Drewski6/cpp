/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:15:11 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/11 18:05:14 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructors , Copy Constructor, Destructor
AForm::AForm(std::string const name_val, int gradeReqToSign_val,
             int gradeReqToExec_val)
    : _name(name_val), _signedStatus(false),
      _gradeReqToSign(gradeReqToSign_val), _gradeReqToExec(gradeReqToExec_val) {
  if (_gradeReqToSign <= 0 || _gradeReqToExec <= 0)
    throw GradeTooHighException();
  if (_gradeReqToSign > 150 || _gradeReqToExec > 150)
    throw GradeTooLowException();
};

AForm::AForm(AForm const &source)
    : _name(source._name), _signedStatus(source._signedStatus),
      _gradeReqToSign(source._gradeReqToSign),
      _gradeReqToExec(source._gradeReqToExec) {
  *this = source;
};

AForm::~AForm(void){};

// Overloaded Operators
AForm &AForm::operator=(AForm const &rhs) {
  if (this == &rhs)
    return (*this);
  return (*this);
};

// Public Methods
std::string AForm::getName() const { return _name; };

bool AForm::getSignedStatus() const { return _signedStatus; };

int AForm::getGradeReqToSign() const { return _gradeReqToSign; };

int AForm::getGradeReqToExec() const { return _gradeReqToExec; };

void AForm::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > _gradeReqToSign)
    throw GradeTooLowException();
  _signedStatus = true;
};

// Exception Class Implementations
AForm::GradeTooHighException::GradeTooHighException(){};
AForm::GradeTooHighException::~GradeTooHighException() throw(){};
const char *AForm::GradeTooHighException::what() const throw() {
  return ("Grade Too High");
}

AForm::GradeTooLowException::GradeTooLowException(){};
AForm::GradeTooLowException::~GradeTooLowException() throw(){};
const char *AForm::GradeTooLowException::what() const throw() {
  return ("Grade Too Low");
}

AForm::FormNotSignedException::FormNotSignedException(){};
AForm::FormNotSignedException::~FormNotSignedException() throw(){};
const char *AForm::FormNotSignedException::what() const throw() {
  return ("Form Not Signed");
}

// Overloaded Stream Insertion Operator
std::ostream &operator<<(std::ostream &os, const AForm &f) {
  std::stringstream ss;
  ss << "========== AForm Info ==========\n";
  ss << "Name               : " << f.getName() << "\n";
  ss << "Signed Status      : " << f.getSignedStatus() << "\n";
  ss << "Grade Req'd To Sign: " << f.getGradeReqToSign() << "\n";
  ss << "Grade Req'd To Exec: " << f.getGradeReqToExec() << "\n";
  os << ss.str();
  return os;
};
