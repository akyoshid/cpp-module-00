/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:20:11 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/11 14:12:12 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <limits>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(){
}

Account::Account(int initial_deposit){
	bool	success = false;
	if (initial_deposit < 0
		|| getNbAccounts() == std::numeric_limits<int>::max()
		|| getTotalAmount() > std::numeric_limits<int>::max() - initial_deposit){
		_accountIndex = -1;
		_amount = 0;
	}else{
		_nbAccounts++;
		_totalAmount += initial_deposit;
		_accountIndex = _nbAccounts - 1;
		_amount = initial_deposit;
		success = true;
	}
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	if (success)
		std::cout << ";amount:" << _amount << ";created" << std::endl;
	else
		std::cout << ";creation:refused" << std::endl;
}

Account::~Account(){
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

int	Account::getNbAccounts(){
	return _nbAccounts;
}
int	Account::getTotalAmount(){
	return _totalAmount;
}

int	Account::getNbDeposits(){
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(){
	return _totalNbWithdrawals;
}

int	Account::checkAmount() const{
	return _amount;
}

void	Account::displayAccountsInfos(){
	_displayTimestamp();
	std::cout
		<< " accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< std::endl;
}

void	Account::displayStatus() const{
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

void	Account::_displayTimestamp(){
	std::time_t now = std::time(NULL);
	std::tm* timeinfo = std::localtime(&now);
	std::cout << "["
		<< std::setfill('0')
		<< std::setw(4) << (timeinfo->tm_year + 1900)
		<< std::setw(2) << (timeinfo->tm_mon + 1)
		<< std::setw(2) << timeinfo->tm_mday
		<< "_"
		<< std::setw(2) << timeinfo->tm_hour
		<< std::setw(2) << timeinfo->tm_min
		<< std::setw(2) << timeinfo->tm_sec
		<< "]"
		<< std::setfill(' ');
}

void	Account::makeDeposit(int deposit){
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";p_amount:" << _amount;
	if (_accountIndex < 0
		|| deposit <= 0
		|| _amount > std::numeric_limits<int>::max() - deposit
		|| _totalAmount > std::numeric_limits<int>::max() - deposit
		|| _nbDeposits == std::numeric_limits<int>::max()){
		std::cout
			<< ";deposit:refused"
			<< std::endl;
	}else{
		std::cout
			<< ";deposit:" << deposit
			<< ";amount:" << (_amount += deposit)
			<< ";nb_deposits:" << ++_nbDeposits
			<< std::endl;
		_totalAmount += deposit;
		_totalNbDeposits++;
	}
}

bool	Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	std::cout
		<< " index:" << _accountIndex
		<< ";p_amount:" << _amount;
	if (_accountIndex < 0
		|| withdrawal <= 0
		|| _nbWithdrawals == std::numeric_limits<int>::max()
		|| _amount - withdrawal < 0){
		std::cout
			<< ";withdrawal:refused"
			<< std::endl;
		return false;
	}else{
		std::cout
			<< ";withdrawal:" << withdrawal
			<< ";amount:" << (_amount -= withdrawal)
			<< ";nb_withdrawals:" << ++_nbWithdrawals
			<< std::endl;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return true;
	}
}
