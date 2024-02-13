/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:10:31 by dpentlan          #+#    #+#             */
/*   Updated: 2024/02/10 15:02:32 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>

#include "Account.hpp"

// Static Class Attribute initialization
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructors
Account::Account(int initial_deposit) {
  // set instance variables
  _amount = initial_deposit;
  _accountIndex = _nbAccounts;
  _nbDeposits = 0;
  _nbWithdrawals = 0;

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
// [19920104_091532] index:7;amount:8942;closed
void Account::_displayTimestamp(void) {
  // Declare variables
  std::time_t raw_time; // time_t struct that contains the raw time info.
  std::tm *local_time =
      NULL; // pointer to tm struct that contains time info broken up into
            // time componenets (seconds, minutes, hours, days, etc).

  // Get the current time
  std::time(&raw_time);
  local_time = std::localtime(&raw_time);

  // Convert to human readable format
  char str_time[80];
  std::strftime(str_time, sizeof(str_time), "%Y%m%d_%H%M%S", local_time);

  std::cout << "[" << str_time << "] ";
  return;
};

// Testing:
// Use this command to get data without timestamps
// ./account | awk '{print substr($0, index($0, " ") + 1)}' > temp1.txt
// Use this command to get the data from the school provided log
// cat path/to/log.file | awk '{print substr($0, index($0, " ") + 1)}' >
// temp2.txt
// Compare with: diff temp1.txt temp2.txt
