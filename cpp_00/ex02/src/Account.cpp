/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:53:54 by flverge           #+#    #+#             */
/*   Updated: 2024/06/12 10:30:57 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"
#include <ctime>
#include <sstream>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructors and Destructors
Account::Account( void ){}

Account::Account( int initial_desposit ){
	
	_totalAmount += initial_desposit;
	_accountIndex = this->getNbAccounts();
	_nbAccounts++;
	_amount = initial_desposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	
	_displayTimestamp();
	
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;

}

Account::~Account(){
	
	_displayTimestamp();
	
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed";
	if (_accountIndex != 7)
		std::cout << std::endl;
}

// Public members

int Account::getNbAccounts( void ){
	return _nbAccounts;
}

int Account::getTotalAmount( void ){
	return _totalAmount;
}

int Account::getNbDeposits( void ){
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals( void ){
	return Account::_totalNbWithdrawals;
}

void Account:: displayAccountsInfos( void ){
	
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;

}

void Account::makeDeposit( int deposit ){
	
	if (deposit >= 0)
	{
		int pre_amount = _amount;
		_amount += deposit;
		_totalAmount+= deposit;
		_totalNbDeposits++;
		_nbDeposits++;

		_displayTimestamp();

		std::cout << " index:" << _accountIndex << ";p_amount:" << pre_amount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
	}
	else
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:ERROR (deposit can't be negative)" << std::endl;
	
}

bool Account::makeWithdrawal( int withdrawal ){
	
	_displayTimestamp();

	int pre_amount = _amount;

	std::cout << " index:" << _accountIndex << ";p_amount:" << pre_amount << ";withdrawal:";

	if (checkAmount() - withdrawal < 0 or withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	else
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
}

int Account::checkAmount( void )const{
	
	return _amount;
}

void Account::displayStatus( void )const{
	_displayTimestamp();

	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// Private members

void Account::_displayTimestamp( void ){
	
	std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    // Create a stringstream to format the timestamp
    std::stringstream ss;

    // Write timestamp to stringstream
    // std::put_time is not available in C++98, so we use strftime instead
    char buffer[16];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", now);
    ss << buffer;

    // Return the timestamp
    std::cout << "[" << ss.str() << "]";

	// ! Un-comment this line for better comparing
    // std::cout << "[19920104_091532]";
	
}