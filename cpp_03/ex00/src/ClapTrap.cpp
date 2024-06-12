/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:42:57 by flverge           #+#    #+#             */
/*   Updated: 2024/06/12 15:52:58 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap( void ){}

ClapTrap::ClapTrap( string nameInput ) :
_name(nameInput), _hitPoints(10), _energyPoints(10), _attackDamage(0){}

ClapTrap::ClapTrap( const ClapTrap& copy ){ *this = copy; }


// Destructors
ClapTrap::~ClapTrap( void ){}


void ClapTrap::attack( const string& target ){
	
	if (!_energyPoints)
	{
		_energyPoints--;
		printNoEndl("ClapTrap");
		printColorNoEndl(GREEN, _name);
		printNoEndl("attacks");
		printColorNoEndl(HIGH_INTENSITY_YELLOW, target);
		printNoEndl(", causing");
		// printColorNoEndl(HIGH_INTENSITY_RED, _attackDamage);
		std::cout << HIGH_INTENSITY_RED << _attackDamage << RESET;
		print("points of damage!");
	}
	else
		std::cout << HIGH_INTENSITY_RED << _name << RESET << "has no energy points left" << std::endl;
}


void ClapTrap::takeDamage( unsigned int amount ){
	
	
}


void ClapTrap::beRepaired( unsigned int amount ){
	
	_energyPoints--;
	_hitPoints += amount;
	
}

// Getters
const string& ClapTrap::getName( void )const{ return this->_name; }

const unsigned int& ClapTrap::getHitPoints( void )const{ return this->_hitPoints; }

const unsigned int& ClapTrap::getEnergyPoints( void )const{	return this->_energyPoints; }

const unsigned int& ClapTrap::getAttackDamage( void )const{ return this->_attackDamage; }


// Setters
void ClapTrap::setHitPoints( unsigned int inputHitPoints ){ _hitPoints = inputHitPoints; }

void ClapTrap::setEnergyPoints( unsigned int inputEnergyPoints ){ _energyPoints = inputEnergyPoints; }

void ClapTrap::setAttackDamage( unsigned int inputAttackDamage ){ _attackDamage = inputAttackDamage; }


ClapTrap& ClapTrap::operator=( const ClapTrap& right_operator ){
	if (this != &right_operator){
		this->_hitPoints = right_operator._hitPoints;
		this->_energyPoints = right_operator._energyPoints;
		this->_attackDamage = right_operator._attackDamage;
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const ClapTrap& right_input ){
	output_stream << right_input.getName();
	output_stream << right_input.getHitPoints();
	output_stream << right_input.getEnergyPoints();
	output_stream << right_input.getAttackDamage();
	return output_stream;
}