/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:53:54 by flverge           #+#    #+#             */
/*   Updated: 2024/06/11 18:21:44 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"

// Constructors and Destructors
Account::Account( void ){}

Account::Account( int initial_desposit){
	
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
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ){
	return _totalNbWithdrawals;
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