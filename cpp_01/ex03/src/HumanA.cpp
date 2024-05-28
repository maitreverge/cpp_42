/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:49 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 20:45:54 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

HumanA::HumanA(/* args */)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack( void ){
	printColorNoEndl(RED, this->getName());
	printNoEndl(" attacks with their ");
	printColor(GREEN, _weapon.getType());
}

const std::string& HumanA::getName( void )const{
	return this->_name;
}

void HumanA::setName( std::string input){
	this->_name = input;
}

