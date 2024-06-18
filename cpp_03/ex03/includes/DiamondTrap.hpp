/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:46:02 by flverge           #+#    #+#             */
/*   Updated: 2024/06/18 13:34:55 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:

	DiamondTrap( void );
	string _name; // same name as in the ClapTrap class 

public:

	DiamondTrap( string nameInput);
	DiamondTrap( const DiamondTrap& copy );
	DiamondTrap& operator=( const DiamondTrap& right_operator );
	~DiamondTrap();

	const string& getName( void )const;

	void whoAmI( void );

	void attack( string target );

};

ostream& operator<<( ostream& output_stream, const DiamondTrap& input );