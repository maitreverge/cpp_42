/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:04:28 by flverge           #+#    #+#             */
/*   Updated: 2024/06/02 16:28:13 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.hpp"

Utils::Utils( const string target, const string remplace ) :
	_targetString(target), _replacingString(remplace) {}

const string& Utils::getReplace( void )const{
	return this->_replacingString;
}

const string& Utils::getTarget( void )const{
	return this->_targetString;
}

void Utils::areStringEqual( void )const{
	if (this->_targetString == this->_replacingString)
	{
		printColor(RED, "⛔ argv[1] and argv[2] are identical ⛔");
		exit(EXIT_FAILURE);
	}
}

Utils::~Utils(){}

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
