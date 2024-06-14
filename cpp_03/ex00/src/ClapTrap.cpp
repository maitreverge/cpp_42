/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:42:57 by flverge           #+#    #+#             */
/*   Updated: 2024/06/14 13:31:15 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap( void ){
	
	 // ! TO DO : display constructor names
}

ClapTrap::ClapTrap( string nameInput ) :
_name(nameInput), _hitPoints(10), _maxHealth(_hitPoints), _energyPoints(10), _attackDamage(6){}

ClapTrap::ClapTrap( const ClapTrap& copy ){ *this = copy; }


// Destructors
ClapTrap::~ClapTrap( void ){

	// ! TO DO : display constructor names
}

/**
 * @brief Function expects 3 inputs :
 * 
 * `ATTACK` : Print message for the `attack` action.
 * `TAKE_DAMAGE` : Print message for the `takeDamage` action.
 * `BE_REPAIRED` : Print message for the `beRepaired` action.
 * 
 * @param message 
 */
void ClapTrap::printFunctionMessage( e_printingActions message, string target )const{
	
	switch (message)
	{
		case ATTACK:
			printNoEndl("ClapTrap ");
			printColorNoEndl(GREEN, _name);
			printNoEndl(" attacks");
			printColorNoEndl(HIGH_INTENSITY_YELLOW, target);
			printNoEndl(", causing ");
			std::cout << HIGH_INTENSITY_RED << _attackDamage << RESET;
			print(" points of damage!");
			break;
		case TAKE_DAMAGE:
			printNoEndl("ClapTrap ");
			printColorNoEndl(GREEN, _name);
			printNoEndl(" takes ");
			printColorNoEndl(HIGH_INTENSITY_YELLOW, target);
			print(" points of damage!\n");
			break;
		case BE_REPAIRED:
			printNoEndl("ClapTrap ");
			printColorNoEndl(GREEN, _name);
			printNoEndl(" heals himself ");
			printColorNoEndl(HIGH_INTENSITY_GREEN, target);
			print(" points health.");
			break;
		case NO_ENERGY:
			printNoEndl("ClapTrap ");
			printColorNoEndl(GREEN, _name);
			printColor(HIGH_INTENSITY_RED, "has no ENERGY left 🪫");
			break;
		case NO_HEALTH:
			printNoEndl("ClapTrap ");
			printColorNoEndl(GREEN, _name);
			printColor(HIGH_INTENSITY_RED, "has no HEALTH left 💔");
			break;
		default:
			break;
	}
}

void ClapTrap::attack( const string& target ){
	
	if (_energyPoints and _hitPoints){
		_energyPoints--;
		printFunctionMessage(ATTACK, target);
	}
	else if (!_energyPoints)
		printFunctionMessage(NO_ENERGY, target);
		// std::cout << HIGH_INTENSITY_RED << _name << RESET << " has no energy points left 🪫" << std::endl;
}


void ClapTrap::takeDamage( unsigned int amount ){
	
	if (_hitPoints){
		if (amount > _hitPoints)
			_hitPoints = 0;
		else
			_hitPoints -= amount;
		printFunctionMessage(TAKE_DAMAGE, customItoA(amount));
	}
	else
		printFunctionMessage(NO_HEALTH, customItoA(amount));
}


void ClapTrap::beRepaired( unsigned int amount ){
	
	if (_energyPoints){
		_energyPoints--;
		_hitPoints += amount;
		updateMaxHealth();
		printFunctionMessage(BE_REPAIRED, customItoA(amount));
	}
	else
		printFunctionMessage(NO_ENERGY, customItoA(amount));
}

// Getters
const string& ClapTrap::getName( void )const{ return this->_name; }

const unsigned int& ClapTrap::getHitPoints( void )const{ return this->_hitPoints; }

const unsigned int& ClapTrap::getEnergyPoints( void )const{	return this->_energyPoints; }

const unsigned int& ClapTrap::getAttackDamage( void )const{ return this->_attackDamage; }


// Setters
void ClapTrap::setHitPoints( unsigned int inputHitPoints ){ _hitPoints = inputHitPoints; }

void ClapTrap::updateEnergyPoints( int inputEnergyPoints ){ _energyPoints += inputEnergyPoints; }

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

void	ClapTrap::updateMaxHealth( void ){
	
	if (this->_hitPoints > this->_maxHealth)
		this->_maxHealth = this->_hitPoints;
}

/////////////////////////////////////////////////////////////////////////

void ClapTrap::printHealthBar( int enemy ){
	
	// Prints extra spaces for 
	if (enemy){
		for (size_t i = 0; i < 55; i++)
			printNoEndl(" ");
	}
	
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
	for (size_t i = _hitPoints * 2; i < _maxHealth * 2; i++)
		printColorNoEndl(RED, MEDIUM_BLOCK);
	
	cout << endl;
	if (enemy){
		for (size_t i = 0; i < 55; i++)
			printNoEndl(" ");
	}
	printNoEndl( "🔪");
	std::cout << "  " << BACKGROUND_HIGH_INTENSITY_WHITE << _attackDamage << RESET  << endl;
	
	if (enemy){
		for (size_t i = 0; i < 55; i++)
			printNoEndl(" ");
	}
	
	// printColorNoEndl(BACKGROUND_HIGH_INTENSITY_CYAN, "🔋");
	printNoEndl( "🔋");
	std::cout << "  " << BACKGROUND_HIGH_INTENSITY_WHITE << _energyPoints << RESET ;
	// 🔋


	// * PRINT ENERGY POINTS
	for (size_t i = 0; i < _energyPoints * 2; i++)
		printColorNoEndl(HIGH_INTENSITY_YELLOW, FULL_BLOCK);
	// for (size_t i = _energyPoints * 2; i < _energyPoints * 2; i++)
	// 	printColorNoEndl(YELLOW, MEDIUM_BLOCK);
	
	// cout << endl;
}

void ClapTrap::displayPikachu( void )const{

cout << endl;

cout << "░░░░░░░░▀████▀▄▄░░░░░░░░░░░░░░▄█" << endl;
cout << "░░░░░░░░░░█▀" << BACKGROUND_YELLOW << "░░░░" << RESET << "▀▀▄▄▄▄▄" << "░░░░▄▄▀▀█" << endl;
cout << "░░▄░░░░░░░░█ " << BACKGROUND_YELLOW <<  "░░░░░░░░░░" << RESET << "▀▀▀▀▄" << BACKGROUND_YELLOW <<  "░░" << RESET << "▄▀" << endl;
cout << "░▄▀" << BACKGROUND_YELLOW <<  "░" << RESET << "▀▄░░░░░░▀▄" << BACKGROUND_YELLOW <<  "░░░░░░░░░░░░░░" << RESET << "▀▄▀░" << endl;
cout << "▄▀" << BACKGROUND_YELLOW <<  "░░░░" << RESET <<  "█░░░░░█▀" << BACKGROUND_YELLOW <<  "░░░" << RESET << "▄█▀▄" << BACKGROUND_YELLOW <<  "░░░░░░░░" << RESET <<  "▄█░" << endl;
cout << "▀▄" << BACKGROUND_YELLOW <<  "░░░░░" << RESET << "▀▄░░█" << BACKGROUND_YELLOW <<  "░░░░░" << RESET <<  "▀██▀" << BACKGROUND_YELLOW << "░░░░░" << RESET <<  "██▄█░░" << endl;
cout << "░▀▄" << BACKGROUND_YELLOW << "░░░░" << RESET << "▄▀░█" << BACKGROUND_YELLOW << "░░░" << RESET <<  RED << "▄██▄" << RESET << BACKGROUND_YELLOW << "░░░" << RESET << "▄" << BACKGROUND_YELLOW << "░░" << RESET << "▄" << BACKGROUND_YELLOW << "░░" << RESET << "▀▀" << BACKGROUND_YELLOW << "░" << RESET << "█░" << endl;
cout << "░░█" << BACKGROUND_YELLOW << "░░" << RESET << "▄▀░░█" << BACKGROUND_YELLOW << "░░░░" << RESET << RED << "▀██▀" << RESET << BACKGROUND_YELLOW << "░░░░" << RESET << "▀▀" << BACKGROUND_YELLOW << "░" << RESET << "▀▀" << BACKGROUND_YELLOW << "░░" << RESET << "▄▀░" << endl;
cout << "░█" << BACKGROUND_YELLOW << "░░░" << RESET << "█░░█" << BACKGROUND_YELLOW << "░░░░░░" << RESET << "▄▄" << BACKGROUND_YELLOW << "░░░░░░░░░░░" << RESET << "▄▀░░" << endl;


}

void ClapTrap::displayShrek( void )const{
	
cout << endl;

printColor(BOLD_GREEN, "                               				⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ");
printColor(BOLD_GREEN, "                               				⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ");
printColor(BOLD_GREEN, "                               				⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀ ");
printColor(BOLD_GREEN, "                               				⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆⠀⠀⠀⠀⠀⠀⠀ ");
printColor(BOLD_GREEN, "                               				⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆ ");
printColor(BOLD_GREEN, "                               				⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿ ");
printColor(BOLD_GREEN, "                               				⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉⠀⠀⠀⠀⠀ ");
printColor(BOLD_GREEN, "                               				⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀ ");
printColor(BOLD_GREEN, "                               				⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀ ");
printColor(BOLD_GREEN, "                               				⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀ ");
printColor(BOLD_GREEN, "                               				⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀ ");
printColor(BOLD_GREEN, "                               				⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀ ");
printColor(BOLD_GREEN, "                               				⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀ ");
printColor(BOLD_GREEN, "                               				⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀ ");
printColor(BOLD_GREEN, "                               				⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉");


}