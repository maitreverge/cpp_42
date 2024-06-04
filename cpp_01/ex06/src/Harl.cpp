/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:58:32 by flverge           #+#    #+#             */
/*   Updated: 2024/06/04 11:28:51 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl(const string input) :
	_message(input){
		ptrDebug = &Harl::debug;
		ptrInfo = &Harl::info;
		ptrWarning = &Harl::warning;
		ptrError = &Harl::error;
}

Harl::~Harl(){}

const string& Harl::getMessage( void )const{
	return this->_message;
}

void Harl::debug( void )const{
	print("[ DEBUG ]");
	printColor(YELLOW, "🐛 Hello, this is a DEBUG message 🐛");
}


void Harl::info( void )const{
	print("[ INFO ]");
	printColor(YELLOW, "👋 Hello, this is a INFO message 👋");
}


void Harl::warning( void )const{
	print("[ WARNING ]");
	printColor(YELLOW, "☢️ Hello, this is a WARNING message ☢️");
}


void Harl::error( void )const{
	print("[ ERROR ]");
	printColor(YELLOW, "⛔ Hello, this is a ERROR message ⛔");
}

void	print( string str ){
	cout << str << endl;
}

void	printNoEndl( string str ){
	cout << str;
}

void	printColor( string COLOR, string str ){
	cout << COLOR << str << RESET << endl;
}

void	printColorNoEndl( string COLOR, string str ){
	cout << COLOR << str << RESET;
}

void clearScreen(void){
	cout << "\x1B[2J\x1B[H" << endl;
}
