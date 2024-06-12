/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:42:57 by flverge           #+#    #+#             */
/*   Updated: 2024/06/12 15:33:12 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap( void ){}

ClapTrap::ClapTrap( string nameInput ) :
_name(nameInput), _hitPoints(10), _energyPoints(10), _attackdamage(0){}


ClapTrap::ClapTrap( const ClapTrap& copy ){ *this = copy; }


ClapTrap::~ClapTrap( void ){}

void ClapTrap::attack( const string& target ){
	
	// ! TO DO
}


void ClapTrap::takeDamage( unsigned int amount ){
	
	// ! TO DO
	
}


void ClapTrap::beRepaired( unsigned int amount ){
	
	// ! TO DO
	
}

const string& ClapTrap::getName( void )const{ return this->_name; }

const unsigned int& ClapTrap::getHitPoints( void )const{ return this->_hitPoints; }

const unsigned int& ClapTrap::getEnergyPoints( void )const{	return this->_energyPoints; }

const unsigned int& ClapTrap::getAttackDamage( void )const{ return this->_attackdamage; }

void ClapTrap::setHitPoints( unsigned int inputHitPoints ){ _hitPoints = inputHitPoints; }

void ClapTrap::setEnergyPoints( unsigned int inputEnergyPoints ){ _energyPoints = inputEnergyPoints; }

void ClapTrap::setAttackDamage( unsigned int inputAttackDamage ){ _attackdamage = inputAttackDamage; }


ClapTrap& ClapTrap::operator=( const ClapTrap& right_operator ){
	if (this != &right_operator){
		// Reassign every value with the getter value 
		// this->_foo = right_operator.getFoo()
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const ClapTrap& right_input ){
	//output_stream << right_input.PutAGetterFunctionhere();
	return output_stream;
}