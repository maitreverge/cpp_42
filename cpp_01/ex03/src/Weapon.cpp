/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:45 by flverge           #+#    #+#             */
/*   Updated: 2024/06/02 12:06:37 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( string input ) : _type(input){
	// this->setType(input);
}

Weapon::~Weapon( void ){}

const string& Weapon::getType( void )const{
	return this->_type;
}

void Weapon::setType( string input){
	this->_type = input;
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