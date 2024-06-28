/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:36:46 by flverge           #+#    #+#             */
/*   Updated: 2024/06/28 10:46:13 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{

public:

	Character( void );
	Character( string nameInput );
	Character( const Character& copy );
	Character& operator=( const Character& right_operator );
	~Character();

	const string& getName( void )const; // done
	void equip( AMateria* m );
	void unequip( int idx );
	void use( int idx, ICharacter& target );

};

ostream& operator<<( ostream& output_stream, const Character& input );


// ---------- Functions declarations ---------------


Character::Character( void ) : ICharacter(){

	for (size_t i = 0; i < 4; i++)
	{
		this->slots[i] = 0; // ? OR NULL 
	}
	
}

Character::Character( string nameInput ) : ICharacter(), _name(nameInput){};



Character::Character( const Character& copy ) : ICharacter(copy){
		
	*this = copy;
}


Character::~Character( void ){}


const string& Character::getName( void )const{ return this->_name; }


void Character::equip( AMateria* m ){

	for (size_t i = 0; i < 4; i++)
	{
		if (this->slots[i] == 0){
			this->slots[i] = m;
			printColor(GREEN, "AMatetira " + m->getType() +
				" successfully equiped on " + this->getName());
			break;	
		}
		else if (i == 3)
			printColor(RED, "Full Inventory, can't equip Materia " + m->getType() +
				" on Character " + this->getName());
	}
	return ;
}

void Character::unequip( int idx ){

	if (this->slots[idx] == 0)
		printColor(RED, "Unequiping " + this->getName() +
			" is impossible at given index " + customItoA(idx) + " (index already empty)");
	else {

		this->slots[idx] = 0;
		printColor(RED, "Unequiping " + this->getName() + " successfull !");
	}
}




Character& Character::operator=( const Character& right_operator ){

	if (this != &right_operator){
		f
		// Reassign every value with the getter value 
		// this->_foo = right_operator.getFoo()
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const Character& right_input ){

	//output_stream << right_input.PutAGetterFunctionhere();
	return output_stream;
}
