/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:57:23 by flverge           #+#    #+#             */
/*   Updated: 2024/10/02 13:11:24 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
class ICharacter;

class AMateria
{

protected:

	string _type;

public:

	AMateria( void );
	AMateria( const string &type );
	AMateria( const AMateria& copy );
	AMateria& operator=( const AMateria& right_operator );
	virtual ~AMateria();

	const string& getType() const;

	virtual AMateria* clone() const = 0;

	virtual void use(ICharacter& target);

};

ostream& operator<<( ostream& output_stream, const AMateria& input );


// ---------- Functions declarations ---------------


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


AMateria::~AMateria( void ){}

const string& AMateria::getType() const{ return this->_type; }

// void	AMateria::use(ICharacter& target){
	
// 	printColorNoEndl(BOLD_BLUE, "* shoots an ice bolt at ");
// 	printColorNoEndl(BOLD_GREEN, target.getName());
// 	printColor(BOLD_BLUE, " *");
// }


ostream& operator<<( ostream& output_stream, const AMateria& right_input ){

	// output_stream << right_input.PutAGetterFunctionhere();

	return output_stream;
}
