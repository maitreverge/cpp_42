/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:58:17 by flverge           #+#    #+#             */
/*   Updated: 2024/06/04 10:08:58 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl( void ){
	/*
	! this->ptrDebug = &this->debug;
	
	This makes no sense because we do not work with
	the current instance of the class 
	but rather the class itself
	
	! Harl::ptrDebug = &Harl::debug;
	
	The line Harl::ptrDebug = &Harl::debug; is not valid in C++
	because ptrDebug is not a static member of the class Harl.
	
	The :: operator is used to access static members,
	which belong to the class itself rather than to any particular instance of the class.

	In contrast, ptrDebug is a non-static member, which means it belongs to each individual instance of the class.
	Therefore, you need to use the . or -> operator to access it, depending on whether you have an object or a pointer to an object.
	
	*/
	ptrDebug = &Harl::debug;
	ptrInfo = &Harl::info;
	ptrWarning = &Harl::warning;
	ptrError = &Harl::error;
}


Harl::~Harl(){}


void Harl::debug( void )const{
	printColor(YELLOW, "🐛 Hello, this is a DEBUG message 🐛");
}


void Harl::info( void )const{
	printColor(YELLOW, "👋 Hello, this is a INFO message 👋");
}


void Harl::warning( void )const{
	printColor(YELLOW, "☢️ Hello, this is a WARNING message ☢️");
}


void Harl::error( void )const{
	printColor(YELLOW, "⛔ Hello, this is a ERROR message ⛔");
}


void Harl::complain( string level ){

	// Declaration of pointers to member functions
	// void (this->*ptrDebug)( void ) = &this->::debug;

	// void (this->*ptrDebug)( void ) = &this->debug;

	// void(Harl::*ptrDebug)( void ) const = &Harl::debug;
	
	// ! TO DO
	/*
	faire en sorte de pouvoir faire un switch case sur des strings
	*/

	// ! maybe use binary masks
	switch (level[0])
	{
		case 'D': // debug
			(this->*ptrDebug)();
			break;
		case 'I': // info
			(this->*ptrInfo)();
			break;
		case 'W': // warning
			(this->*ptrWarning)();
			break;
		case 'E': // error
			(this->*ptrError)();
			break;
		default:
			printColor(RED, "⛔ Failed switch statement ⛔");
			break;
	}
}

// -------------- UTILS FUNCTIONS

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