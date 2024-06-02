/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:48 by flverge           #+#    #+#             */
/*   Updated: 2024/06/02 13:01:19 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( string inputName ) : _name(inputName){
	/*
		! By default, HumanB does not take any Weapon.
		! Then this _weapon attribute is set to NULL;
	*/
	this->_weapon = NULL;
}

HumanB::~HumanB(){}

/**
 * @brief Takes the reference to the given Weapon.
 * Assign the adress of the reference to the pointer.
 * 
 * @param inputWeapon 
 */
void HumanB::setWeapon( Weapon& inputWeapon ){
	this->_weapon = &inputWeapon; // Assign the adress of the reference to the pointer.
}

/**
 * @brief Checks if the HumanB has a Weapon.
 * If not, print a message to inform the user.
 * If yes, print the name of the HumanB and the type of the Weapon.
 * 
 */
void HumanB::attack( void )const{
	printColorNoEndl(RED, this->_name);
	if (!_weapon) // no weapon given, because pointer set to `NULL`
		printColor(YELLOW, " has no Weapon, is vulnerable, and need to have a Weapon Set !");
	else // _weapon exists, then a weapon has been set
	{
		printNoEndl(" attacks with their ");
		printColor(GREEN, _weapon->getType());
	}
}