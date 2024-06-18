/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:42:57 by flverge           #+#    #+#             */
/*   Updated: 2024/06/18 13:42:38 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

// Constructors

// Default constructor is private
ClapTrap::ClapTrap( void ){}

ClapTrap::ClapTrap( string nameInput ) :
_name(nameInput), _hitPoints(100), _maxHealth(_hitPoints), _energyPoints(100), _attackDamage(30){

	printColor(BOLD_GREEN, "ClapTrap "+_name+" created !");
}

ClapTrap::ClapTrap( const ClapTrap& copy ){ 

	*this = copy;
	printColor(BOLD_YELLOW, "Copy Constructor called !");
}


// Destructors
ClapTrap::~ClapTrap( void ){

	printColor(BOLD_RED, "ClapTrap "+_name+" destroyed !");
}

/**
 * @brief Function expects 3 inputs :
 * 
 * `ATTACK` : Print message for the `attack` action.
 * `TAKE_DAMAGE` : Print message for the `takeDamage` action.
 * `BE_REPAIRED` : Print message for the `beRepaired` action.
 * `NO_ENERGY` : Print message when instance got no energy left.
 * `NO_HEALTH` : Print message when instance got no health left.
 * `NO_DAMAGE` : Print message when instance got no `attackDamage`.
 * 
 * ! Those displays messages are only for the ClapTrap class
 * 
 * @param message 
 */
void ClapTrap::printFunctionMessage( e_printingActions message, string target )const{
	
	switch (message)
	{
		case ATTACK_CLAP:
			printNoEndl("ClapTrap ");
			printColorNoEndl(GREEN, _name);
			printNoEndl(" attacks ");
			printColorNoEndl(HIGH_INTENSITY_YELLOW, target);
			printNoEndl(", causing ");
			std::cout << HIGH_INTENSITY_RED << _attackDamage << RESET;
			print(" points of damage!");
			break;
		case ATTACK_SCAV:
			printNoEndl("ScavTrap ");
			printColorNoEndl(GREEN, _name);
			printNoEndl(" inflicts ");
			printColorNoEndl(HIGH_INTENSITY_YELLOW, target);
			printNoEndl(", causing a total of ");
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
			printColor(HIGH_INTENSITY_RED, " has no ENERGY left 🪫");
			break;
		case NO_HEALTH:
			printNoEndl("ClapTrap ");
			printColorNoEndl(GREEN, _name);
			printColor(HIGH_INTENSITY_RED, " is already dead 💀");
			break;
		case NO_DAMAGE:
			printNoEndl("ClapTrap ");
			printColorNoEndl(GREEN, _name);
			printColor(HIGH_INTENSITY_RED, " can't make any damage !");
		default:
			break;
	}
}

void ClapTrap::attack( const string& target ){
	
	if (_energyPoints){
		_energyPoints--;
		printFunctionMessage(ATTACK_CLAP, target);
	}
	else
		printFunctionMessage(NO_ENERGY, target);
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

	output_stream << "Name : " << right_input.getName();
	output_stream << "\nHit Points : " << right_input.getHitPoints();
	output_stream << "\nEnergy Points : " << right_input.getEnergyPoints();
	output_stream << "\nAttack Points : " << right_input.getAttackDamage();
	return output_stream;
}

void	ClapTrap::updateMaxHealth( void ){
	
	if (this->_hitPoints > this->_maxHealth)
		this->_maxHealth = this->_hitPoints;
}

/**
 * @brief Functions which prints the `_hitPoints`, `_energyPoints` and `_attackDamage`.
 * 
 * Only the first two variables are represented with a bar.
 * 
 * `enemy` Optional parametter is for right alignment printing.
 * @param enemy 
 */
void ClapTrap::printStats( int enemy )const{
	
	// Prints extra spaces for shrek
	if (enemy)
		rightAlign();
	
	// * PRINT HEALTH BAR
	if (!_hitPoints)
		printNoEndl("💔  ");
	else{
		switch (_hitPoints / 3)
		{
			case 0:
				printNoEndl("❤️   ");
				break;
			case 1:
				printNoEndl("💛  ");
				break;
			default:
				printNoEndl("💚  ");
				break;
		}
	}
	printColorNoEndl(BACKGROUND_HIGH_INTENSITY_WHITE, customItoA(_hitPoints));

	// Print the health bar, first the actual health, then the missing health based on the maxHealth
	for (size_t i = 0; i < _hitPoints / 2; i++)
		printColorNoEndl(HIGH_INTENSITY_GREEN, FULL_BLOCK);
	for (size_t i = _hitPoints / 2; i < _maxHealth / 2; i++)
		printColorNoEndl(RED, MEDIUM_BLOCK);
	cout << endl;
	
	if (enemy)
		rightAlign();
	
	// * PRINT ATTACK DAMAGE
	printNoEndl( "🔪  ");
	printColor(BACKGROUND_HIGH_INTENSITY_WHITE, customItoA(_attackDamage));
	
	if (enemy)
		rightAlign();
	
	// * PRINT ENERGY POINTS BAR
	printNoEndl( "🔋  ");
	printColorNoEndl(BACKGROUND_HIGH_INTENSITY_WHITE, customItoA(_energyPoints));

	for (size_t i = 0; i < _energyPoints / 2; i++)
		printColorNoEndl(HIGH_INTENSITY_YELLOW, FULL_BLOCK);
	
}

void ClapTrap::displayPikachu( void )const{

	cout << endl;
	if (_hitPoints) {
		cout <<  "░░░░░░░░▀████▀▄▄░░░░░░░░░░░░░░▄█" << endl;
		cout <<  "░░░░░░░░░░█▀" << BOLD_HIGH_INTENSITY_BLUE << "░░░░" << RESET << "▀▀▄▄▄▄▄" << "░░░░▄▄▀▀█" << endl;
		cout <<  "░░▄░░░░░░░░█ " << BOLD_HIGH_INTENSITY_BLUE <<  "░░░░░░░░░░" << RESET << "▀▀▀▀▄" << BOLD_HIGH_INTENSITY_BLUE <<  "░░" << RESET << "▄▀" << endl;
		cout <<  "░▄▀" << BOLD_HIGH_INTENSITY_BLUE <<  "░" << RESET << "▀▄░░░░░░▀▄" << BOLD_HIGH_INTENSITY_BLUE <<  "░░░░░░░░░░░░░░" << RESET << "▀▄▀░" << endl;
		cout <<  "▄▀" << BOLD_HIGH_INTENSITY_BLUE <<  "░░░░" << RESET <<  "█░░░░░█▀" << BOLD_HIGH_INTENSITY_BLUE <<  "░░░" << RESET << "▄█▀▄" << BOLD_HIGH_INTENSITY_BLUE <<  "░░░░░░░░" << RESET <<  "▄█░" << endl;
		cout <<  "▀▄" << BOLD_HIGH_INTENSITY_BLUE <<  "░░░░░" << RESET << "▀▄░░█" << BOLD_HIGH_INTENSITY_BLUE <<  "░░░░░" << RESET <<  "▀██▀" << BOLD_HIGH_INTENSITY_BLUE << "░░░░░" << RESET <<  "██▄█░░" << endl;
		cout <<  "░▀▄" << BOLD_HIGH_INTENSITY_BLUE << "░░░░" << RESET << "▄▀░█" << BOLD_HIGH_INTENSITY_BLUE << "░░░" << RESET <<  RED << "▄██▄" << RESET << BOLD_HIGH_INTENSITY_BLUE << "░░░" << RESET << "▄" << BOLD_HIGH_INTENSITY_BLUE << "░░" << RESET << "▄" << BOLD_HIGH_INTENSITY_BLUE << "░░" << RESET << "▀▀" << BOLD_HIGH_INTENSITY_BLUE << "░" << RESET << "█░" << endl;
		cout <<  "░░█" << BOLD_HIGH_INTENSITY_BLUE << "░░" << RESET << "▄▀░░█" << BOLD_HIGH_INTENSITY_BLUE << "░░░░" << RESET << RED << "▀██▀" << RESET << BOLD_HIGH_INTENSITY_BLUE << "░░░░" << RESET << "▀▀" << BOLD_HIGH_INTENSITY_BLUE << "░" << RESET << "▀▀" << BOLD_HIGH_INTENSITY_BLUE << "░░" << RESET << "▄▀░" << endl;
		cout <<  "░█" << BOLD_HIGH_INTENSITY_BLUE << "░░░" << RESET << "█░░█" << BOLD_HIGH_INTENSITY_BLUE << "░░░░░░" << RESET << "▄▄" << BOLD_HIGH_INTENSITY_BLUE << "░░░░░░░░░░░" << RESET << "▄▀░░" << endl;
	}
	else{} // does not print the character if he got no life left

}

void ClapTrap::displayShrek( void )const{
	
	cout << endl;

	if (_hitPoints) {
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
	else{} // does not print the character if he got no life left

}