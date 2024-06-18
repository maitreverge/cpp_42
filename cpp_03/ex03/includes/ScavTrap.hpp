/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:44:20 by flverge           #+#    #+#             */
/*   Updated: 2024/06/18 11:53:58 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	
private:

	bool _isGate;

public:

	ScavTrap( void );
	ScavTrap( string nameInput ); 
	ScavTrap( const ScavTrap& copy );
	ScavTrap& operator=( const ScavTrap& right_operator );
	~ScavTrap();

	bool getIsGate( void )const;

	void attack( const string& target );
	
	void guardGate( void );
	
};

ostream& operator<<( ostream& output_stream, const ScavTrap& input );