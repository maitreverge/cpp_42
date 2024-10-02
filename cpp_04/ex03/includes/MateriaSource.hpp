/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:04:31 by flverge           #+#    #+#             */
/*   Updated: 2024/10/02 21:14:54 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define INVENTORY_SIZE 4

class MateriaSource : public IMateriaSource
{

private:

	AMateria* _inventory[INVENTORY_SIZE];

public:

	MateriaSource( void );
	MateriaSource( MateriaSource& copy );
	MateriaSource& operator=( MateriaSource& right_operator );
	~MateriaSource();

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

	AMateria* getInventory(const unsigned short i);


};

ostream& operator<<( ostream& output_stream, const MateriaSource& input );


// ---------- Functions declarations ---------------


MateriaSource::MateriaSource( void ){

	// Null init inventory
	for (size_t i = 0; i < INVENTORY_SIZE; i++)
	{
		_inventory[i] = 0;
	}
}


MateriaSource::MateriaSource( MateriaSource& copy ) {
	
	AMateria* allocMateria;
	
	// Deep copy of inventory
	for (size_t i = 0; i < INVENTORY_SIZE; ++i)
	{
		allocMateria = copy.getInventory(i);
		if (!allocMateria)
			_inventory[i] = 0;
		else
			_inventory[i] = allocMateria->clone();
	}
	
}


MateriaSource& MateriaSource::operator=( MateriaSource& right_operator ){

	if (this != &right_operator){
		
		// Clean local inventory
		for (size_t i = 0; i < 4; ++i)
		{
			if (_inventory[i])
				delete _inventory[i];
		}
		
		// Reassign right_operator inventory
		AMateria* allocMateria;
		for (size_t i = 0; i < INVENTORY_SIZE; ++i)
		{
			allocMateria = right_operator.getInventory(i);
			if (!allocMateria)
				_inventory[i] = 0;
			else
				_inventory[i] = allocMateria->clone();
		}
	}
	return *this;
}


MateriaSource::~MateriaSource( void ){

	for (size_t i = 0; i < INVENTORY_SIZE; ++i)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

AMateria* MateriaSource::getInventory(const unsigned short i){

	if ( i > INVENTORY_SIZE ){
		throw std::out_of_range("Index Inventory is out of bounds");
	}
	return _inventory[i];
}


ostream& operator<<( ostream& output_stream, const MateriaSource& right_input ){

	// output_stream << right_input.PutAGetterFunctionhere();

	return output_stream;
}
