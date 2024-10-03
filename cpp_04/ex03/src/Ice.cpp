/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:22:30 by flverge           #+#    #+#             */
/*   Updated: 2024/10/03 10:22:51 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice"){}


Ice::Ice( const Ice& copy ) : AMateria(copy){
	
	this->_type = copy._type;
}


Ice& Ice::operator=( const Ice& right_operator ){

	if (this != &right_operator){
		this->_type = right_operator._type;
	}
	return *this;
}


Ice::~Ice( void ){}


AMateria* Ice::clone() const{ return new Ice; }

void Ice::use(ICharacter& target){

	printColorNoEndl(BOLD_BLUE, "* shoots an ice bolt at ");
	printColorNoEndl(BOLD_GREEN, target.getName());
	printColor(BOLD_BLUE, " *");
}

ostream& operator<<( ostream& output_stream, const Ice& right_input ){

	output_stream << "Type of Ice :";
	output_stream << right_input.getType();

	return output_stream;
}
