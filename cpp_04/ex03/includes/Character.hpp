/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:36:46 by flverge           #+#    #+#             */
/*   Updated: 2024/06/25 15:38:10 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{

private:

	// Some private members

public:

	Character( void );
	Character( const Character& copy );
	Character& operator=( const Character& right_operator );
	~Character();

	const string& getName( void )const = 0;
	void equip( AMateria* m ) = 0;
	void unequip( int idx ) = 0;
	void use( int idx, ICharacter& target ) = 0;

};

ostream& operator<<( ostream& output_stream, const Character& input );


// ---------- Functions declarations ---------------


Character::Character( void ){}


Character::Character( const Character& copy ){ *this = copy; }


Character::~Character( void ){}


Character& Character::operator=( const Character& right_operator ){

	if (this != &right_operator){
		// Reassign every value with the getter value 
		// this->_foo = right_operator.getFoo()
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const Character& right_input ){

	//output_stream << right_input.PutAGetterFunctionhere();
	return output_stream;
}
