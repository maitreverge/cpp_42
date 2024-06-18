/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:46:14 by flverge           #+#    #+#             */
/*   Updated: 2024/06/18 14:03:15 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ){}

DiamondTrap::DiamondTrap( string nameInput ) :
	ClapTrap(nameInput+"_clap_name"), ScavTrap(nameInput), FragTrap(nameInput), _name(nameInput){

	printColor(BACKGROUND_HIGH_INTENSITY_GREEN, "DiamondTrap "+_name+" created !");

	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}


DiamondTrap::DiamondTrap( const DiamondTrap& copy ) {*this = copy; }


DiamondTrap::~DiamondTrap( void ){

	printColor(BACKGROUND_HIGH_INTENSITY_RED, "DiamondTrap "+_name+" destroyed !");
}


DiamondTrap& DiamondTrap::operator=( const DiamondTrap& right_operator ){
	
	if (this != &right_operator){
		this->_hitPoints = right_operator._hitPoints;
		this->_energyPoints = right_operator._energyPoints;
		this->_attackDamage = right_operator._attackDamage;
	}
	return *this;
}

const string& DiamondTrap::getName( void )const{

	return this->DiamondTrap::_name; // return _name from DiamondTrap, not ClapTrap
}

void DiamondTrap::whoAmI( void ){

	// Display both _name from Diamond and _name from Clap
	printColor(YELLOW, "DiamondTrap name : " +this->getName());
	printColor(YELLOW, "ClapTrap name : " +ClapTrap::getName());
}

void DiamondTrap::attack( string target ){

	printColor(RED, "DIAMONDTRAP calling Scavtrap attack");
	ScavTrap::attack(target);
}


ostream& operator<<( ostream& output_stream, const DiamondTrap& right_input ){
	
	output_stream << "Name : " << right_input.getName();
	output_stream << "\nHit Points : " << right_input.getHitPoints();
	output_stream << "\nEnergy Points : " << right_input.getEnergyPoints();
	output_stream << "\nAttack Points : " << right_input.getAttackDamage();
	return output_stream;
}