/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:53:54 by flverge           #+#    #+#             */
/*   Updated: 2024/06/11 18:45:30 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructors and Destructors
Account::Account( void ){}

Account::Account( int initial_desposit ){
	
	std::cout << "Hello" << std::endl;
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
	// ! TO DO
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
	// ! TO DO
}