/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:45 by flverge           #+#    #+#             */
/*   Updated: 2024/05/29 09:14:25 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string input ) : _type(input){
	// this->setType(input);
}

Weapon::~Weapon( void ){}

const std::string& Weapon::getType( void )const{
	return this->_type;
}

void Weapon::setType( std::string input){
	this->_type = input;
}

void	print( std::string str ){
	std::cout << str << std::endl;
}

void	printNoEndl( std::string str ){
	std::cout << str <<;
}

void	printColor( std::string COLOR, std::string str ){
	std::cout << COLOR << str << RESET << std::endl;
}

void	printColorNoEndl( std::string COLOR, std::string str ){
	std::cout << COLOR << str << RESET;
}