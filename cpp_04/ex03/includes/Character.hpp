/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:19:26 by flverge           #+#    #+#             */
/*   Updated: 2024/10/02 20:17:17 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

#define DUMP_SIZE 1000

class Character : public ICharacter
{

private:

	Character( void );
	string		_name;
	AMateria*	_inventory[4];
	AMateria*	_dump[DUMP_SIZE];

public:
	
	Character( const string &nameInput );
	Character( Character& copy );
	Character& operator=( Character& right_operator );
	~Character();

	string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	AMateria* getInventory(const unsigned short i);

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

	for (size_t i = 0; i < DUMP_SIZE; ++i)
	{
		_dump[i] = 0;
	}
	
}


Character::Character( Character& copy ) :
	_name(copy.getName()){

	AMateria* allocMateria;
	for (size_t i = 0; i < 4; ++i)
	{
		allocMateria = copy.getInventory(i); // accessing to the inventory
		if (!allocMateria)
			_inventory[i] = 0;
		else
			_inventory[i] = allocMateria->clone(); // deep copy by cloning
	}
}


Character& Character::operator=( Character& right_operator ){

	if (this != &right_operator){

		// clean the actual inventory
		for (size_t i = 0; i < 4; ++i)
		{
			if (_inventory[i])
				delete _inventory[i];
		}

		// deep copy
		AMateria* allocMateria;
		for (size_t i = 0; i < 4; ++i)
		{
			allocMateria = right_operator.getInventory(i); // accessing to the inventory
			if (!allocMateria)
				_inventory[i] = 0;
			else
				_inventory[i] = allocMateria->clone(); // deep copy by cloning
		}
		
	}
	return *this;
}


Character::~Character( void ){

	// Clean allocated Materia
	for (size_t i = 0; i < 4; ++i)
	{
		if (_inventory[i])
			delete _inventory[i];
	}

	// Clean Dump
	for (size_t i = 0; i < DUMP_SIZE; ++i)
	{
		if (_dump[i])
			delete _dump[i];
	}
}

string const & Character::getName() const{ return this->_name; }


void Character::equip(AMateria* m){

	if (!m)
		throw std::bad_alloc();
	
	for (size_t i = 0; i < 4; ++i)
	{
		if ( !_inventory[i] )
		{
			_inventory[i] = m;
			printColor(BOLD_GREEN, m->getType() + "successfully added");
			return;
		}
	}
	printColor(BOLD_RED, this->getName() + "'s inventory is full, can't add " + m->getType());
	delete m; // delete the input if it can't be allocated
}

void Character::unequip(int idx){


	
}

void Character::use(int idx, ICharacter& target){

	
}

AMateria* Character::getInventory(const unsigned short i){

	if ( i > 4 ){
		throw std::out_of_range("Index is out of bouds");
	}
	return _inventory[i];
}



ostream& operator<<( ostream& output_stream, const Character& right_input ){

	output_stream << "Name of Character = ";
	output_stream << right_input.getName();

	return output_stream;
}
