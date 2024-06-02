/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:49 by flverge           #+#    #+#             */
/*   Updated: 2024/06/02 12:32:54 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( string inputName, Weapon& starterWeapon) :
	_name(inputName), _weapon(starterWeapon){}


HumanA::~HumanA(){}

void HumanA::attack( void ){
	printColorNoEndl(RED, getName());
	printNoEndl(" attacks with their ");
	printColor(GREEN, _weapon.getType());
}

const string& HumanA::getName( void ) const{
	return this->_name;
}