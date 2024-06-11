/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:53:54 by flverge           #+#    #+#             */
/*   Updated: 2024/06/11 19:13:33 by flverge          ###   ########.fr       */
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

Account::~Account(){}

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
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << std::endl;
}

void Account::makeDeposit( int deposit ){
	// ! TO DO
}

bool Account::makeWithdrawal( int withdrawal ){
	// ! TO DO
}

int Account::checkAmount( void )const{
	// ! TO DO
}

void Account::displayStatus( void )const{
	// ! TO DO
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
}