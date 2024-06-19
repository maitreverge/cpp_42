/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:33:54 by flverge           #+#    #+#             */
/*   Updated: 2024/06/19 20:44:57 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ){}


Animal::Animal( string inputName ) : _type(inputName) {}


Animal::Animal( const Animal& copy ){ *this = copy; }


Animal::~Animal( void ){}


Animal& Animal::operator=( const Animal& right_operator ){
	
	if (this != &right_operator){
		
		this->_type = right_operator.getType();
	}
	return *this;
}


const string&	Animal::getType( void )const{ return this->_type; }


void	Animal::setType( const string& input){ this->_type = input; }

void Animal::makeSound( void )const{

	printColorNoEndl(RED, "THE ANIMAL ");
	printColor(GREEN, "makes a sound ! Nobody knows what kind of sound, because this is an Animal");
}


ostream& operator<<( ostream& output_stream, const Animal& right_input ){
	
	output_stream << "Type of Animal Class = " << right_input.getType();
	return output_stream;
}