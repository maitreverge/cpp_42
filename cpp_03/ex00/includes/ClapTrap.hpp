/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:42:15 by flverge           #+#    #+#             */
/*   Updated: 2024/06/12 15:47:04 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_template.hpp"
#include <ncurses.h>

class ClapTrap
{
private:

	ClapTrap( void );
	const string _name;
	unsigned int _hitPoints; // LIFE 
	unsigned int _energyPoints; // MANA
	unsigned int _attackDamage; // SUBSTRACT TO LIFE
	
public:

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
	void setEnergyPoints( unsigned int inputEnergyPoints );
	void setAttackDamage( unsigned int inputAttackDamage );
	

};

ostream& operator<<( ostream& output_stream, const ClapTrap& input );