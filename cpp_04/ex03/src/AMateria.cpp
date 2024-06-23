/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:31:59 by flverge           #+#    #+#             */
/*   Updated: 2024/06/23 13:39:42 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ){}


AMateria::AMateria( const string& type ) : _type(type) {}


AMateria& AMateria::operator=( const AMateria& right_operator ){

	if (this != &right_operator){
		
		this->_type = right_operator.getType();
	}
	return *this;
}

AMateria::~AMateria( void ){}

const string& AMateria::getType( void )const { return this->_type; }

// void AMateria::use( ICharacter& target ) {

// 	// ! TO DO
// }

ostream& operator<<( ostream& output_stream, const AMateria& right_input ){

	output_stream << "Type of AMateria class = " << right_input.getType();
	return output_stream;
}