/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:10:31 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/13 15:44:52 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Account.hpp"

int _nbAccounts = 0;
int _totalAmount = 0;
int _totalNbDeposits = 0;
int _totalNbWithdrawals = 0;

// Constructors
Account::Account(int initial_deposit) {
  _amount = initial_deposit;
  _totalAmount += _amount;
  _nbAccounts += 1;
};

// Destructor
Account::~Account() {
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "closed" << std::endl;
};

// Public Methods
void Account::displayAccountsInfos() {
  std::cout << "hi";
  std::cout << std::endl;
}

// Private Methods
