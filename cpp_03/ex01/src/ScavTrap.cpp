/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:44:38 by flverge           #+#    #+#             */
/*   Updated: 2024/06/17 15:13:16 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap( void ){}


ScavTrap::ScavTrap( const ScavTrap& copy ){ *this = copy; }


ScavTrap::~ScavTrap( void ){}


ScavTrap& ScavTrap::operator=( const ScavTrap& right_operator ){
	if (this != &right_operator){
		this->_hitPoints = right_operator._hitPoints;
		this->_energyPoints = right_operator._energyPoints;
		this->_attackDamage = right_operator._attackDamage;
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const ScavTrap& right_input ){
	output_stream << right_input.getName();
	output_stream << right_input.getHitPoints();
	output_stream << right_input.getEnergyPoints();
	output_stream << right_input.getAttackDamage();
	return output_stream;
}


void ScavTrap::guardGate( void ){

	printNoEndl("ScavTrap");
	printColorNoEndl(GREEN, this->getName());
	print("is now in Guard Gate Mode 🛡️");
}
