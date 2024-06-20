/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:28:47 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 12:51:36 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal( "" ){}

Cat::Cat( string catName ) : Animal( catName ){

	printColor(GREEN, catName+" Cat has been created 🐈");
	extraLine();
}

Cat::Cat( const Cat& copy ) : Animal( copy ) {}

Cat::~Cat( void ){

	
	printColor(GREEN, "Cat destroyed 😿");
	extraLine();
}

void Cat::makeSound( void )const{

	printColorNoEndl(RED, "THE CAT ");
	printColor(GREEN, "meows 😺");
}


Cat& Cat::operator=( const Cat& right_operator ){

	if (this != &right_operator){
		
		this->_type = right_operator.getType();
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const Cat& right_input ){

	output_stream << "Type of Cat Class = " << right_input.getType();
	return output_stream;
}
