/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:49:57 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/12 19:50:02 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class PmergeMe {
public:
  // Constructors , Copy Constructor, Destructor
  PmergeMe(void);
  PmergeMe(PmergeMe const &source);
  ~PmergeMe(void);
  
  // Overloaded Operators
  PmergeMe &operator=(PmergeMe const &rhs);

private:
};
