/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:42:15 by flverge           #+#    #+#             */
/*   Updated: 2024/06/14 13:26:37 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
#include <unistd.h>
// #include <stdio.h>
#include <stdlib.h>

class ClapTrap
{
private:

	ClapTrap( void );
	const string _name;
	unsigned int _hitPoints; // LIFE
	unsigned int _maxHealth; // MAX LIFE
	unsigned int _energyPoints; // MANA
	unsigned int _attackDamage; // SUBSTRACT TO LIFE
	
public:

	typedef enum e{
		ATTACK,
		TAKE_DAMAGE,
		BE_REPAIRED,
		NO_ENERGY,
		NO_HEALTH
	}		e_printingActions;

	ClapTrap( string nameInput );
	ClapTrap( const ClapTrap& copy );
	ClapTrap& operator=( const ClapTrap& right_operator );
	~ClapTrap();

	void attack( const string& target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );

	const string& getName( void )const;
	const unsigned int& getHitPoints( void )const;
	const unsigned int& getEnergyPoints( void )const;
	const unsigned int& getAttackDamage( void )const;

	void setHitPoints( unsigned int inputHitPoints );
	void updateEnergyPoints( int inputEnergyPoints );
	void setAttackDamage( unsigned int inputAttackDamage );
	
	void updateMaxHealth( void );

	// Extra for printing video-game like
	void printFunctionMessage( e_printingActions message, string target )const;
	void printHealthBar( int enemy = 0 );
	void displayPikachu( void )const;
	void displayShrek( void )const;

};

ostream& operator<<( ostream& output_stream, const ClapTrap& input );