/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:20:09 by flverge           #+#    #+#             */
/*   Updated: 2024/10/03 10:31:30 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ){}


AMateria::AMateria( const AMateria& copy ) :
	_type(copy._type) {}

AMateria::AMateria( const string &type ):
	_type(type){}


AMateria& AMateria::operator=( const AMateria& right_operator ){

   if (this != &right_operator){
		// Reassign every value with the getter value 
		// this->_foo = right_operator.getFoo()
	}
	return *this;
}

// Need to code the method despite can't being called
void AMateria::use(ICharacter& target){

	(void)(target);
}


AMateria::~AMateria( void ){}

const string& AMateria::getType() const{ return this->_type; }