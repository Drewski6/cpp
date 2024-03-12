/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 08:54:44 by dpentlan          #+#    #+#             */
/*   Updated: 2024/03/12 10:25:08 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class Intern {
public:
  // Constructors , Copy Constructor, Destructor
  Intern(void);
  Intern(Intern const &source);
  ~Intern(void);

  // Overloaded Operators
  Intern &operator=(Intern const &rhs);

  // Public Methods
  AForm *makeForm(std::string formName, std::string targetName) const;

private:
};
