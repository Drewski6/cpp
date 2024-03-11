/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:15:02 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/10 14:09:28 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <sstream>
#include <string>

class Form {
public:
  // Constructors , Copy Constructor, Destructor
  Form(std::string const name_val, int _gradeReqToSign, int _gradeReqToExec);
  Form(Form const &source);
  ~Form(void);

  // Overloaded Operators
  Form &operator=(Form const &rhs);

  // Public Methods
  std::string getName() const;
  bool getSignedStatus() const;
  int getGradeReqToSign() const;
  int getGradeReqToExec() const;
  void beSigned(const Bureaucrat &b);

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

private:
  std::string const _name;
  bool _signedStatus;
  int const _gradeReqToSign;
  int const _gradeReqToExec;
};

// Overloaded Stream Insertion Operator
std::ostream &operator<<(std::ostream &os, const Form &b);
