/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:34:06 by flverge           #+#    #+#             */
/*   Updated: 2024/06/23 13:45:49 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{

protected:

	// Some protected members

public:

	Ice( void );
	Ice( const Ice& copy );
	Ice& operator=( const Ice& right_operator );
	~Ice();

	AMateria* clone( void ) const; // PURE VIRTUAL FROM AMATERIA


};

ostream& operator<<( ostream& output_stream, const Ice& input );


// ---------- Functions declarations ---------------


Ice::Ice( void ) : AMateria("ice") {}


Ice::Ice( const Ice& copy ) : AMateria("ice") { *this = copy; }


Ice::~Ice( void ){}


Ice& Ice::operator=( const Ice& right_operator ){

	if (this != &right_operator){
		// Reassign every value with the getter value 
		this->_type = right_operator.getType();
	}
	return *this;
}

AMateria* Ice::clone( void )const{

	return new Ice();
}


ostream& operator<<( ostream& output_stream, const Ice& right_input ){

	output_stream << "Type of Ice Class = " << right_input.getType();
	return output_stream;
}
