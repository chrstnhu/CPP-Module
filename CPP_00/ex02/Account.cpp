/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:44:49 by chrhu             #+#    #+#             */
/*   Updated: 2024/07/24 16:13:39 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

// Initialize
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Construction
Account::Account() {}

Account::Account( int initial_deposit ) {
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;


	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";created" 
			<< std::endl;
}

// Destruction
Account::~Account( void ) {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";closed" 
			<< std::endl;
}

// Getters :
int Account::getNbAccounts(void) {	
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void) {	
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void) {	
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {	
	return (Account::_totalNbWithdrawals);
}

//Print account status
void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";deposits:" << this->_nbDeposits
			<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

// Print account infos
void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()
			<< ";total:" << getTotalAmount()
			<< ";deposits:" << getNbDeposits()
			<< ";withdrawals:" << getNbWithdrawals()
			<< std::endl;
}

// Make a deposit, add to initial deposit
void Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	this->_totalAmount += deposit;
	std::cout << " index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";deposit:" << deposit
			<< ";amount:" << this->_amount + deposit
			<< ";nb_deposits:" << this->_nbDeposits
			<< std::endl;
	this->_amount += deposit;
}

// Make a withdrawal, remove from initial deposit
bool Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount;
	if (this->_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		this->_totalAmount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal
				<< ";amount:" << this->_amount
				<< ";nb_withdrawals:" << this->_nbWithdrawals
				<< std::endl;
	}
	return (true);
}

// Display the timestamp
void	Account::_displayTimestamp( void ) 
{
	time_t timestamp = time(NULL);

	char buf[18];
    if (std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", std::localtime(&timestamp)))
                std::cout << buf;

}
