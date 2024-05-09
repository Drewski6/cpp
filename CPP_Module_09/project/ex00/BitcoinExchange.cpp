/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:32:17 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/09 18:32:22 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors , Copy Constructor, Destructor
BitcoinExchange::BitcoinExchange(void){};
BitcoinExchange::BitcoinExchange(BitcoinExchange const &source) { *this = source; };
BitcoinExchange::~BitcoinExchange(void){};

// Overloaded Operators
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
  if (this == &rhs)
    return (*this);
  // Additional code here if you need a deep copy.
  return (*this);
};
