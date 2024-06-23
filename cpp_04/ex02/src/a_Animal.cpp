/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:11:31 by flverge           #+#    #+#             */
/*   Updated: 2024/06/23 12:30:09 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "a_Animal.hpp"

a_Animal::a_Animal( void ){

	
	printColor(HIGH_INTENSITY_YELLOW, "Random nameless a_Animal has been created 🫥");
	extraLine();
}


a_Animal::a_Animal( string inputName ) : _type(inputName) {
	
	printColor(HIGH_INTENSITY_YELLOW, "Random a_Animal has been created 🫥");
	extraLine();
}


a_Animal::a_Animal( const a_Animal& copy ){ *this = copy; }


a_Animal::~a_Animal( void ){

	printColor(BOLD_HIGH_INTENSITY_YELLOW, "a_Animal destroyed 💥");
	extraLine();
}


a_Animal& a_Animal::operator=( const a_Animal& right_operator ){
	
	if (this != &right_operator){
		
		this->_type = right_operator.getType();
	}
	return *this;
}


const string&	a_Animal::getType( void )const{ return this->_type; }


void	a_Animal::setType( const string& input){ this->_type = input; }

// void a_Animal::makeSound( void )const{

// 	printColorNoEndl(RED, "THE ANIMAL ");
// 	printColor(GREEN, "makes a sound ! Nobody knows what kind of sound, because this is an a_Animal");
// }

void a_Animal::displayThought( void )const{

	printColor(RED, "Selected a_Animal have no Brain, then no Thoughts");
}



ostream& operator<<( ostream& output_stream, const a_Animal& right_input ){
	
	output_stream << "Type of Animal Class = " << right_input.getType();
	return output_stream;
}