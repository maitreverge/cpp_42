/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:58:17 by flverge           #+#    #+#             */
/*   Updated: 2024/06/03 16:04:50 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl( void ){}


Harl::~Harl(){}


void Harl::debug( void )const{
	printColor(YELLOW, "🐛 Hello, this is a DEBUG message 🐛")
}


void Harl::info( void )const{
	printColor(YELLOW, "ℹ️ Hello, this is a INFO message ℹ️")
}


void Harl::warning( void )const{
	printColor(YELLOW, "☢️ Hello, this is a WARNING message ☢️")
}


void Harl::error( void )const{
	printColor(YELLOW, "⛔ Hello, this is a ERROR message ⛔")
}


void Harl::complain( string level ){

	// ! TO DO
	/*
	faire en sorte de pouvoir faire un switch case sur des strings
	*/
	switch (level)
	{
	case string("DEBUG"):
		/* code */
		break;
	
	default:
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