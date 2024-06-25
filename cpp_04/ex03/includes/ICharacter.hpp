/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:28:02 by flverge           #+#    #+#             */
/*   Updated: 2024/06/25 15:33:39 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class ICharacter
{

public:

	virtual ~ICharacter( void );
	virtual const string& getName( void )const = 0;
	virtual void equip( AMateria* m ) = 0;
	virtual void unequip( int idx ) = 0;
	virtual void use( int idx, ICharacter& target ) = 0;
	
};

ostream& operator<<( ostream& output_stream, const ICharacter& input );


// ---------- Functions declarations ---------------


ICharacter::~ICharacter( void ){}