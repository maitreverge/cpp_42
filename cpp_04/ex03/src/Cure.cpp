/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:21:58 by flverge           #+#    #+#             */
/*   Updated: 2024/10/03 10:22:17 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure"){}


Cure::Cure( const Cure& copy ) : AMateria(copy){
	
	this->_type = copy._type;
}


Cure& Cure::operator=( const Cure& right_operator ){

   if (this != &right_operator){
		this->_type = right_operator._type;
	}
	return *this;
}


Cure::~Cure( void ){}


AMateria* Cure::clone() const{ return new Cure; }

void Cure::use(ICharacter& target){

	printColorNoEndl(BOLD_BLUE, "* heals ");
	printColorNoEndl(BOLD_GREEN, target.getName());
	printColor(BOLD_BLUE, "'s wounds *");
}


ostream& operator<<( ostream& output_stream, const Cure& right_input ){

	output_stream << "Type of Cure :";
	output_stream << right_input.getType();

	return output_stream;
}