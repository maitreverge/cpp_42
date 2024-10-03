/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:20:53 by flverge           #+#    #+#             */
/*   Updated: 2024/10/03 10:43:08 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ){}


Character::Character( const string &nameInput ) :
	_name(nameInput), _dump_index(0){

	// NULL init each inventory space
	for (size_t i = 0; i < 4; ++i)
	{
		_inventory[i] = 0;
	}

	// NULL init each dump space
	for (size_t i = 0; i < DUMP_SIZE; ++i)
	{
		_dump[i] = 0;
	}
}


Character::Character( Character& copy ) :
	_name(copy.getName()){
	
	AMateria* allocMateria;
	
	// Deep copy of inventory
	for (size_t i = 0; i < 4; ++i)
	{
		allocMateria = copy.getInventory(i); // accessing to the inventory
		if (!allocMateria)
			_inventory[i] = 0;
		else
			_inventory[i] = allocMateria->clone(); // deep copy by cloning
	}

	// Deep copy of dump
	for (size_t i = 0; i < DUMP_SIZE; ++i)
	{
		allocMateria = copy.getDump(i);
		if (!allocMateria)
			_dump[i] = 0;
		else
			_dump[i] = allocMateria->clone();
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

		// Clean the dump
		for (size_t i = 0; i < DUMP_SIZE; ++i)
		{
			if (_dump[i])
				delete _dump[i];
		}

		// deep copy of inventory
		AMateria* allocMateria;
		for (size_t i = 0; i < 4; ++i)
		{
			allocMateria = right_operator.getInventory(i); // accessing to the inventory
			if (!allocMateria)
				_inventory[i] = 0;
			else
				_inventory[i] = allocMateria->clone(); // deep copy by cloning
		}
		
		// deep copy of inventory
		for (size_t i = 0; i < DUMP_SIZE; ++i)
		{
			allocMateria = right_operator.getDump(i);
			if (!allocMateria)
				_dump[i] = 0;
			else
				_dump[i] = allocMateria->clone();
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
			printColor(BOLD_GREEN, m->getType() + " successfully added");
			return;
		}
	}
	printColor(BOLD_RED, this->getName() + "'s inventory is full, can't add " + m->getType());
	delete m; // delete the input if it can't be allocated
}

void Character::unequip(int idx){

	if (!this->getInventory(idx)){
		
		printColor(BOLD_RED, "Targeted intex to unequip is already empty");
		return;
	}
	
	// Add to the Character _dump the current Materia at _inventory[i]
	if (_dump_index >= DUMP_SIZE)
		throw std::out_of_range("Dump Characted is full, this method call will leak memory");
	_dump[_dump_index++] = _inventory[idx];

	// As required by the subject, I decided to move the [idx] Materia
	// from a buffer to another one (we can't delete the Materia in this method)
	_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target){

	// This call might thrown an error.
	AMateria *current = this->getInventory(idx);
	
	current->use(target);
}

AMateria* Character::getInventory(const unsigned short i){

	if ( i > 4 ){
		throw std::out_of_range("Index Inventory is out of bounds");
	}
	return _inventory[i];
}

AMateria* Character::getDump(unsigned int i){

	if ( i > DUMP_SIZE ){
		throw std::out_of_range("Index DUmp is out of bounds");
	}
	return _dump[i];
}


ostream& operator<<( ostream& output_stream, const Character& right_input ){

	output_stream << "Name of Character = ";
	output_stream << right_input.getName();

	return output_stream;
}
