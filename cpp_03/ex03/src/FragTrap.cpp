/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:45:37 by flverge           #+#    #+#             */
/*   Updated: 2024/06/18 14:03:25 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap( void ){}

FragTrap::FragTrap( string nameInput ) : ClapTrap( nameInput ){

	printColor(HIGH_INTENSITY_GREEN, "FragTrap "+_name+" created !");
}


FragTrap::FragTrap( const FragTrap& copy ) : ClapTrap(copy) { *this = copy; }


FragTrap::~FragTrap( void ){

	printColor(HIGH_INTENSITY_RED, "FragTrap "+_name+" destroyed !");
}


FragTrap& FragTrap::operator=( const FragTrap& right_operator ){
	if (this != &right_operator){
		this->_hitPoints = right_operator._hitPoints;
		this->_energyPoints = right_operator._energyPoints;
		this->_attackDamage = right_operator._attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys( void ){

	printNoEndl("FragTrap ");
	printColor(GREEN, this->getName()+" says HI 👋");
}


ostream& operator<<( ostream& output_stream, const FragTrap& right_input ){
	output_stream << "Name : " << right_input.getName();
	output_stream << "\nHit Points : " << right_input.getHitPoints();
	output_stream << "\nEnergy Points : " << right_input.getEnergyPoints();
	output_stream << "\nAttack Points : " << right_input.getAttackDamage();
	return output_stream;
}
