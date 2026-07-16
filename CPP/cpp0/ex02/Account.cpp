/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamjada <alamjada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:11:55 by alamjada          #+#    #+#             */
/*   Updated: 2026/04/08 19:16:11 by alamjada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

Account::Account(void) : _amount(0) {
  this->_accountIndex = Account::getNbAccounts();
  this->_displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";created\n";
  Account::_nbAccounts++;
  Account::_totalAmount += this->_amount;
}

Account::Account(int initial_deposit) : _amount(initial_deposit) {
  this->_accountIndex = Account::getNbAccounts();
  this->_displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";created\n";
  Account::_nbAccounts++;
  Account::_totalAmount += this->_amount;
}

Account::~Account(void) {
  this->_displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed\n";
  Account::_nbAccounts--;
}

void Account::makeDeposit(int deposit) {
  int newAmount = this->_amount + deposit;
  this->_displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount
            << ";deposit:" << deposit << ";amount:" << newAmount
            << ";nb_deposits:" << ++this->_nbDeposits << std::endl;
  Account::_totalAmount += deposit;
  Account::_totalNbDeposits++;
  this->_amount = newAmount;
}

bool Account::makeWithdrawal(int withdrawal) {
  if (withdrawal > this->_amount) {
    this->_displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";p_amount:" << this->_amount << ";withdrawal:refused"
              << std::endl;
    return (false);
  }
  this->_displayTimestamp();
  int newAmount = this->_amount - withdrawal;
  std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount
            << ";withdrawal:" << withdrawal << ";amount:" << newAmount
            << ";nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
  this->_amount = newAmount;
  Account::_totalNbWithdrawals++;
  Account::_totalAmount -= withdrawal;
  return true;
}

int Account::checkAmount(void) const {
  if (this->_amount > 0)
    return (true);
  return (false);
}

void Account::displayStatus(void) const {
  Account::_displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << " accounts:" << Account::_nbAccounts
            << ";total:" << Account::_totalAmount
            << ";deposits:" << Account::_totalNbDeposits
            << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

int Account::getNbAccounts(void) { return (Account::_nbAccounts); }

int Account::getTotalAmount(void) { return (Account::_totalAmount); }

int Account::getNbDeposits(void) { return (Account::_totalNbDeposits); }

int Account::getNbWithdrawals(void) { return (Account::_totalNbWithdrawals); }

void Account::_displayTimestamp(void) {
  char formatedTimestamp[15];
  std::time_t timestamp = std::time(NULL);
  struct std::tm datetime = *std::localtime(&timestamp);
  std::strftime(formatedTimestamp, 15, "%Y%m%d_%H%M%S", &datetime);
  std::cout << "[" << formatedTimestamp << "]";
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
