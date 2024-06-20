/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:33:54 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 12:51:28 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ){

	
	printColor(HIGH_INTENSITY_YELLOW, "Random nameless Animal has been created 🫥");
	extraLine();
}


Animal::Animal( string inputName ) : _type(inputName) {
	
	printColor(HIGH_INTENSITY_YELLOW, "Random Animal has been created 🫥");
	extraLine();
}


Animal::Animal( const Animal& copy ){ *this = copy; }


Animal::~Animal( void ){

	printColor(BOLD_HIGH_INTENSITY_YELLOW, "Animal destroyed 💥");
	extraLine();
}


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