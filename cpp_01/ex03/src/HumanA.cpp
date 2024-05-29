/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:49 by flverge           #+#    #+#             */
/*   Updated: 2024/05/29 09:40:25 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/**
 * @brief Construct a new Human A:: Human A object
 * Initialization list, where the _name private const variable is init with the given inputName
 * Same for private attribute _weapon init with the given starterWeapon.
 * 
 * @param inputName 
 * @param starterWeapon 
 */
HumanA::HumanA(std::string const inputName, Weapon starterWeapon) :
	_name(inputName), _weapon(starterWeapon){}


HumanA::~HumanA(){}

/**
 * @brief Displays the name of the HumanA object
 * and the weapon they are using.
 * 
 */
void HumanA::attack( void ){
	printColorNoEndl(RED, this->_name);
	printNoEndl(" attacks with their ");
	printColor(GREEN, _weapon.getType());
}