/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:48 by flverge           #+#    #+#             */
/*   Updated: 2024/06/02 12:04:55 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

HumanB::HumanB( const string inputName, Weapon* inputWeapon=nullptr ) :
	_name(inputName), _weapon(inputWeapon){}

HumanB::~HumanB(){}

void HumanB::setWeapon( Weapon* inputWeapon ) :
	_weapon(inputWeapon){}

void HumanB::attack( void )const{
	printColorNoEndl(RED, this->_name);
	printNoEndl(" attacks with their ");
	printColor(GREEN, _weapon.getType());
}