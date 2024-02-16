/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:27:34 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/16 19:30:44 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <string>

class IMateriaSource {
public:
  virtual ~IMateriaSource() {}
  virtual void learnMateria(AMateria *) = 0;
  virtual AMateria *createMateria(std::string const &type) = 0;
};
