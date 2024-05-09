/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:31:52 by dpentlan          #+#    #+#             */
/*   Updated: 2024/05/09 18:31:57 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class BitcoinExchange {
public:
  // Constructors , Copy Constructor, Destructor
  BitcoinExchange(void);
  BitcoinExchange(BitcoinExchange const &source);
  ~BitcoinExchange(void);
  
  // Overloaded Operators
  BitcoinExchange &operator=(BitcoinExchange const &rhs);

private:
};
