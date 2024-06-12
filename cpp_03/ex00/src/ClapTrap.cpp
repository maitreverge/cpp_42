/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:42:57 by flverge           #+#    #+#             */
/*   Updated: 2024/06/12 21:33:42 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap( void ){}

ClapTrap::ClapTrap( string nameInput ) :
_name(nameInput), _hitPoints(10), _energyPoints(10), _attackDamage(0){}

ClapTrap::ClapTrap( const ClapTrap& copy ){ *this = copy; }


// Destructors
ClapTrap::~ClapTrap( void ){}


void ClapTrap::attack( const string& target ){
	
	if (_energyPoints and _hitPoints){
		_energyPoints--;
		printNoEndl("ClapTrap");
		printColorNoEndl(GREEN, _name);
		printNoEndl("attacks");
		printColorNoEndl(HIGH_INTENSITY_YELLOW, target);
		printNoEndl(", causing");
		std::cout << HIGH_INTENSITY_RED << _attackDamage << RESET;
		print("points of damage!");
	}
	else
		std::cout << HIGH_INTENSITY_RED << _name << RESET << "has no energy points left" << std::endl;
}


void ClapTrap::takeDamage( unsigned int amount ){
	
	if (_hitPoints){
		_hitPoints -= amount;
		if (_hitPoints < 0){
			_hitPoints = 0;
			printNoEndl("ClapTrap");
			printColorNoEndl(GREEN, _name);
			printColor(HIGH_INTENSITY_RED, "has no life left");
			return ;
		}
	}
	else{
		printNoEndl("ClapTrap");
		printColorNoEndl(GREEN, _name);
		printColor(HIGH_INTENSITY_RED, "is already dead, please stop beating a dead body");
	}
}


void ClapTrap::beRepaired( unsigned int amount ){
	
	if (_energyPoints){
		_energyPoints--;
		_hitPoints += amount;
		printNoEndl("ClapTrap");
		printColorNoEndl(GREEN, _name);
		printNoEndl("has regained"); std::cout << HIGH_INTENSITY_GREEN << amount << RESET;
		print("HEALTH");
	}
	else
		std::cout << HIGH_INTENSITY_RED << _name << RESET << "has no energy points left" << std::endl;
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

/////////////////////////////////////////////////////////////////////////

void ClapTrap::printHealthBar( int enemy )const{
	
	// Prints extra spaces for 
	if (enemy)
		for (size_t i = 0; i < 30; i++)
			printNoEndl(" ");
		
	// 💚 💛 ❤️ 💔
	// Printing emojis depending on health level
	if (!_hitPoints)
		printNoEndl("💔  ");
	else{
		switch (_hitPoints / 3)
		{
			case 0:
				printNoEndl("❤️  ");
				break;
			case 1:
				printNoEndl("💛  ");
				break;
			default:
				printNoEndl("💚  ");
				break;
		}
	}
	std::cout << BACKGROUND_HIGH_INTENSITY_WHITE << _hitPoints << RESET ;

	// printing actual health_bar * 2 for larger bar
	for (size_t i = 0; i < _hitPoints * 2; i++)
		printColorNoEndl(HIGH_INTENSITY_GREEN, FULL_BLOCK);
	for (size_t i = _hitPoints * 2; i < 20; i++)
		printColorNoEndl(RED, MEDIUM_BLOCK);
	
	// printing extra line
	cout << endl;
}