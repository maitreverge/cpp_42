/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:58:32 by flverge           #+#    #+#             */
/*   Updated: 2024/06/04 10:38:17 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl(const string input) :
	_message(input){
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
