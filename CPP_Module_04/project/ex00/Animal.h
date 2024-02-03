/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:54:28 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/03 15:54:32 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
public:
  // Constructors , Copy Constructor, Destructor
  Animal(void);

  Animal(Animal const &source);
  ~Animal(void);

  // Overloaded Operators
  Animal &operator=(Animal const &rhs);

private:
};

#endif // ANIMAL_H //
