/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:10:39 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 13:11:18 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal( "" ){}

WrongCat::WrongCat( string WrongCatName ) : WrongAnimal( WrongCatName ){

	printColor(GREEN, WrongCatName+" WrongCat has been created 🐈");
	extraLine();
}

WrongCat::WrongCat( const WrongCat& copy ) : WrongAnimal( copy ) {}

WrongCat::~WrongCat( void ){

	
	printColor(GREEN, "WrongCat destroyed 😿");
	extraLine();
}

void WrongCat::makeSound( void )const{

	printColorNoEndl(RED, "THE WrongCat ");
	printColor(GREEN, "meows 😺");
}


WrongCat& WrongCat::operator=( const WrongCat& right_operator ){

	if (this != &right_operator){
		
		this->_type = right_operator.getType();
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const WrongCat& right_input ){

	output_stream << "Type of WrongCat Class = " << right_input.getType();
	return output_stream;
}