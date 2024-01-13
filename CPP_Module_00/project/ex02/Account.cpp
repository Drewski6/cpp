/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:10:31 by dpentlan          #+#    #+#             */
/*   Updated: 2024/01/13 16:32:18 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructors
Account::Account(int initial_deposit) {
  // set instance variables
  _amount = initial_deposit;
  _accountIndex = _nbAccounts;

  // increment class-wide attributes
  _totalAmount += _amount;
  _nbAccounts += 1;

  // display message
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "created" << std::endl;
};

// Destructor
Account::~Account() {
  // static modifications
  _nbAccounts -= 1;
  _totalAmount -= _amount;

  // display message
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "closed" << std::endl;
};

// Public Methods

int Account::getNbAccounts(void) { return (_nbAccounts); };

int Account::getTotalAmount(void) { return (_totalAmount); };

int Account::getNbDeposits(void) { return (_totalNbDeposits); };

int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); };

void Account::displayAccountsInfos() {
  // display message
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";";
  std::cout << "total:" << getTotalAmount() << ";";
  std::cout << "deposits:" << getNbDeposits() << ";";
  std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
  int p_amount = _amount;

  // edit account
  _amount += deposit;
  _nbDeposits += 1;
  _totalNbDeposits += 1;
  _totalAmount += deposit;

  // display message // p_amount = previous amount
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "p_amount:" << p_amount << ";";
  std::cout << "deposit:" << deposit << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "nb_deposits:" << _nbDeposits << std::endl;
};

bool Account::makeWithdrawal(int withdrawal) {
  int p_amount = _amount;

  // edit account
  if (withdrawal > _amount) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << p_amount << ";";
    std::cout << "withdrawal:refused" << std::endl;
    return (1);
  }
  _amount -= withdrawal;
  _nbWithdrawals += 1;
  _totalNbWithdrawals += 1;
  _totalAmount -= withdrawal;

  // display message
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "p_amount:" << p_amount << ";";
  std::cout << "withdrawal:" << withdrawal << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
  return (0);
};

int Account::checkAmount(void) const { return (0); };

void Account::displayStatus(void) const {
  // display message
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "deposits:" << _nbDeposits << ";";
  std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
};

// Private Methods
void Account::_displayTimestamp(void) {
  std::cout << "[timestamp_place_holder] ";
  return;
};
