/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:31:59 by flverge           #+#    #+#             */
/*   Updated: 2024/06/25 15:32:11 by flverge          ###   ########.fr       */
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

// ! NO NEED FOR CLONE FUNCTION (it's a pure virtual function)


// Modify this function once implemented
void AMateria::use( ICharacter& target ) {

	if (_type == "ice")
		print("* shoots an ice bolt at <name> *");
	else
		print("* heals <name>'s wounds *");
}