/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:15:02 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/11 19:33:43 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <sstream>
#include <string>

class Bureaucrat;

class AForm {
public:
  // Constructors , Copy Constructor, Destructor
  AForm(std::string const name_val, int _gradeReqToSign, int _gradeReqToExec);
  AForm(AForm const &source);
  virtual ~AForm(void);

  // Overloaded Operators
  AForm &operator=(AForm const &rhs);

  // Public Methods
  std::string getName() const;
  bool getSignedStatus() const;
  int getGradeReqToSign() const;
  int getGradeReqToExec() const;
  void beSigned(Bureaucrat const &b);
  virtual void execute(Bureaucrat const &executor) const = 0;

  // Exception Classes
  class GradeTooHighException : public std::exception {
  public:
    GradeTooHighException();
    virtual ~GradeTooHighException() throw();
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    GradeTooLowException();
    virtual ~GradeTooLowException() throw();
    virtual const char *what() const throw();
  };

  class FormNotSignedException : public std::exception {
  public:
    FormNotSignedException();
    virtual ~FormNotSignedException() throw();
    virtual const char *what() const throw();
  };

private:
  std::string const _name;
  bool _signedStatus;
  int const _gradeReqToSign;
  int const _gradeReqToExec;
};

// Overloaded Stream Insertion Operator
std::ostream &operator<<(std::ostream &os, const AForm &b);
