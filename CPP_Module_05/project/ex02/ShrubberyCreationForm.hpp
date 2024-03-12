/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:22:35 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/11 21:29:22 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm {
public:
  // Constructors , Copy Constructor, Destructor
  ShrubberyCreationForm(std::string target_val);
  ShrubberyCreationForm(ShrubberyCreationForm const &source);
  ~ShrubberyCreationForm(void);

  // Overloaded Operators
  ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

  // Public Methods
  std::string getTarget() const;
  void execute(Bureaucrat const &executor) const;

private:
  std::string const _target;
};
