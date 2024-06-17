/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:44:38 by flverge           #+#    #+#             */
/*   Updated: 2024/06/17 22:11:37 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap( void ){}

ScavTrap::ScavTrap( string nameInput ) : ClapTrap( nameInput ), _isGate( false ){

	printColor(HIGH_INTENSITY_GREEN, "ScavTrap "+_name+" created !");
}


ScavTrap::ScavTrap( const ScavTrap& copy ) : ClapTrap(copy) { *this = copy; }


ScavTrap::~ScavTrap( void ) {

	printColor(BOLD_HIGH_INTENSITY_RED, "ScavTrap "+_name+" destroyed !");
}


ScavTrap& ScavTrap::operator=( const ScavTrap& right_operator ){
	if (this != &right_operator){
		this->_hitPoints = right_operator._hitPoints;
		this->_energyPoints = right_operator._energyPoints;
		this->_attackDamage = right_operator._attackDamage;
	}
	return *this;
}

bool ScavTrap::getIsGate ( void )const{

	return this->_isGate;
}

void ScavTrap::setIsGate( bool value ){

	this->_isGate = value;
}


ostream& operator<<( ostream& output_stream, const ScavTrap& right_input ){
	
	output_stream << "Name : " << right_input.getName();
	output_stream << "\nHit Points : " << right_input.getHitPoints();
	output_stream << "\nEnergy Points : " << right_input.getEnergyPoints();
	output_stream << "\nAttack Points : " << right_input.getAttackDamage();
	return output_stream;
}


void ScavTrap::guardGate( void ){

	printNoEndl("ScavTrap");
	printColorNoEndl(GREEN, this->getName());
	
	if (getIsGate()){

		print("is now in Guard Gate Mode 🛡️");
		this->setIsGate(true);
	}
	else {

		print("is no longer in Guard Gate Mode 🛡️");
		this->setIsGate(false);
		
	}
}

void ScavTrap::attack( const string& target ){

	// ! We need to print a different message here
	if (_energyPoints){
		_energyPoints--;
		printFunctionMessage(ATTACK_SCAV, target);
	}
	else
		printFunctionMessage(NO_ENERGY, target);
}
