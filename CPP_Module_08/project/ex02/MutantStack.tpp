/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:12:14 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/08 20:46:00 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Constructors , Copy Constructor, Destructor
template <typename T, typename C>
MutantStack<T, C>::MutantStack(void){};

template <typename T, typename C>
MutantStack<T, C>::MutantStack(MutantStack const &source) { *this = source; };

template <typename T, typename C>
MutantStack<T, C>::~MutantStack(void){};

// Overloaded Operators
template <typename T, typename C>
MutantStack<T, C> &MutantStack<T, C>::operator=(MutantStack const &rhs) {
  if (this == &rhs)
    return (*this);
  this->c = rhs.c;
  return (*this);
};

