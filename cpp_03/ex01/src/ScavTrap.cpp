/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:44:38 by flverge           #+#    #+#             */
/*   Updated: 2024/06/17 16:52:41 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap( void ){}

ScavTrap::ScavTrap( string nameInput ) : ClapTrap( nameInput ){

	printColor(HIGH_INTENSITY_GREEN, "ScavTrap "+_name+" created !");
}


ScavTrap::ScavTrap( const ScavTrap& copy ){ *this = copy; }


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
	print("is now in Guard Gate Mode 🛡️");
}

void ScavTrap::attack( const string& target ){

	// ! We need to print a different message here
	if (_energyPoints){
		_energyPoints--;
		// printFunctionMessage(ATTACK, target);
		printNoEndl("ScavTrap ");
		printColorNoEndl(GREEN, _name);
		printNoEndl(" inflicts ");
		printColorNoEndl(HIGH_INTENSITY_YELLOW, target);
		printNoEndl(", causing a total of ");
		std::cout << HIGH_INTENSITY_RED << _attackDamage << RESET;
		print(" points of damage!");
	}
	else
		printFunctionMessage(NO_ENERGY, target);
}
