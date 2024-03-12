/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 01:50:52 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/11 19:33:08 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <sstream>
#include <string>

class AForm;

class Bureaucrat {
public:
  // Constructors , Copy Constructor, Destructor
  Bureaucrat(const std::string name_val = "NoName", int grade_val = (150));
  Bureaucrat(Bureaucrat const &source);
  ~Bureaucrat(void);

  // Overloaded Operators
  Bureaucrat &operator=(Bureaucrat const &rhs);

  // Public Methods
  std::string getName(void) const;
  int getGrade(void) const;
  void incGrade(void);
  void decGrade(void);
  void signForm(AForm &f);
  void executeForm(AForm const &form);

  // Built in Exception Classes
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
  const std::string _name;
  unsigned int _grade;
};

// Overloaded Stream Insertion Operator
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
