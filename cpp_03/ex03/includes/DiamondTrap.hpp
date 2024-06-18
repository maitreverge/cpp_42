/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:46:02 by flverge           #+#    #+#             */
/*   Updated: 2024/06/18 11:50:25 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:

	DiamondTrap( void );
	string _name; // same name as in the ClapTrap class 

public:

	DiamondTrap( string nameInput);
	DiamondTrap( const DiamondTrap& copy );
	DiamondTrap& operator=( const DiamondTrap& right_operator );
	~DiamondTrap();

};

ostream& operator<<( ostream& output_stream, const DiamondTrap& input );


// ---------- Functions declarations ---------------


DiamondTrap::DiamondTrap( void ){}

DiamondTrap::DiamondTrap( string nameInput ) : ScavTrap(nameInput), FragTrap(nameInput){

	printColor(HIGH_INTENSITY_GREEN, "DiamondTrap "+_name+" created !");
}


DiamondTrap::DiamondTrap( const DiamondTrap& copy ) : ScavTrap(copy), FragTrap(copy) { *this = copy; }


DiamondTrap::~DiamondTrap( void ){}


DiamondTrap& DiamondTrap::operator=( const DiamondTrap& right_operator ){
	if (this != &right_operator){
		this->_hitPoints = right_operator._hitPoints;
		this->_energyPoints = right_operator._energyPoints;
		this->_attackDamage = right_operator._attackDamage;
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const DiamondTrap& right_input ){
	output_stream << "Name : " << right_input.getName();
	output_stream << "\nHit Points : " << right_input.getHitPoints();
	output_stream << "\nEnergy Points : " << right_input.getEnergyPoints();
	output_stream << "\nAttack Points : " << right_input.getAttackDamage();
	return output_stream;
}
