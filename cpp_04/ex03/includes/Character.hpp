/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:19:26 by flverge           #+#    #+#             */
/*   Updated: 2024/10/02 14:58:30 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{

private:

	Character( void );
	string _name;
	AMateria* _inventory[4];

public:
	
	Character( const string &nameInput );
	Character( const Character& copy );
	Character& operator=( const Character& right_operator );
	~Character();

	string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

};

ostream& operator<<( ostream& output_stream, const Character& input );


// ---------- Functions declarations ---------------


Character::Character( void ){}

Character::Character( const string &nameInput ) :
	_name(nameInput){

	// NULL init each inventory space
	for (size_t i = 0; i < 4; ++i)
	{
		_inventory[i] = 0;
	}
}



Character::Character( const Character& copy ) :
	_name(copy.getName()){}


Character& Character::operator=( const Character& right_operator ){

	if (this != &right_operator){
		this->_name = right_operator.getName();
	}
	return *this;
}


Character::~Character( void ){

	// Clean allocated Materia
	for (size_t i = 0; i < 4; ++i)
	{
		delete _inventory[i];
	}
}

string const & Character::getName() const{ return this->_name; }


void Character::equip(AMateria* m){

	for (size_t i = 0; i < 4; ++i)
	{
		if (! _inventory[i])
		{
			_inventory[i] = m;
			printColor(BOLD_GREEN, m->getType() + "successfully added");
			return;
		}
	}
	
	printColor(BOLD_RED, this->getName() + "'s inventory is full, can't add " + m->getType());
}

void Character::unequip(int idx){

	
}
void Character::use(int idx, ICharacter& target){

	
}


ostream& operator<<( ostream& output_stream, const Character& right_input ){

	output_stream << "Name of Character = ";
	output_stream << right_input.getName();

	return output_stream;
}
