/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:42:07 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/08 17:47:06 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>

class Brain {
public:
  // Constructors , Copy Constructor, Destructor
  Brain(void);
  
  Brain(Brain const &source);
  ~Brain(void);

  // Overloaded Operators
  Brain &operator=(Brain const &rhs);

  // Public Attributes
  std::string ideas[100];

  // Public Methods
  std::string &getIdea(int idea_index);
  void setIdea(int idea_index, std::string idea_content);

private:
};

#endif // BRAIN_H //
