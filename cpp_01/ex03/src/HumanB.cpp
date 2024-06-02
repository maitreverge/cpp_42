/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:48 by flverge           #+#    #+#             */
/*   Updated: 2024/06/02 12:46:39 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( string inputName ) : _name(inputName){
	this->_weapon = NULL;
}

HumanB::~HumanB(){}

void HumanB::setWeapon( Weapon inputWeapon ){
	this->_weapon = &inputWeapon;
}

void HumanB::attack( void )const{
	printColorNoEndl(RED, this->_name);
	if (_weapon)
	{
		printNoEndl(" attacks with their ");
		print(_weapon->getType());
	}
	else // no weapon given
		printColor(YELLOW, " has no Weapon, is vulnerable, and wants you to help him !");
}