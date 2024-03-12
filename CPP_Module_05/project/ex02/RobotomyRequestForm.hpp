/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:22:14 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/11 20:59:42 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <string>

class RobotomyRequestForm : public AForm {
public:
  // Constructors , Copy Constructor, Destructor
  RobotomyRequestForm(std::string target_val);
  RobotomyRequestForm(RobotomyRequestForm const &source);
  ~RobotomyRequestForm(void);

  // Overloaded Operators
  RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

  // Public Methods
  void execute(Bureaucrat const &executor) const;

private:
  std::string const _target;

  int _getRandomNumber() const;
};
