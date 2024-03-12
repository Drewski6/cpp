/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:22:42 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/11 21:29:58 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructors , Copy Constructor, Destructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target_val)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target_val){};

ShrubberyCreationForm::ShrubberyCreationForm(
    ShrubberyCreationForm const &source)
    : AForm(source) {
  *this = source;
};

ShrubberyCreationForm::~ShrubberyCreationForm(void){};

// Overloaded Operators
ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
  if (this == &rhs)
    return (*this);
  return (*this);
};

// Public Methods
std::string ShrubberyCreationForm::getTarget() const { return _target; };

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (this->getSignedStatus() == false)
    throw FormNotSignedException();
  if (executor.getGrade() > this->getGradeReqToExec())
    throw GradeTooLowException();
  std::string fileName = _target + "_shrubbery";
  std::ofstream outFile(fileName.c_str());
  if (!outFile.is_open()) {
    return;
  }
  outFile << "== ASCII TREE ==" << std::endl;
  outFile << "                " << std::endl;
  outFile << "        *       " << std::endl;
  outFile << "       ***      " << std::endl;
  outFile << "      *****     " << std::endl;
  outFile << "     *******    " << std::endl;
  outFile << "    *********   " << std::endl;
  outFile << "       |||      " << std::endl;
  outFile << "----------------" << std::endl;
  outFile << "                " << std::endl;
  outFile << "- for " << this->getTarget() << std::endl;
  outFile << "- from " << executor.getName() << std::endl;
  outFile.close();
};
