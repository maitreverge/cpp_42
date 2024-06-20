/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:03:55 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 13:07:38 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ){

	
	printColor(BOLD_HIGH_INTENSITY_YELLOW, "Random nameless WrongAnimal has been created 🫥");
	extraLine();
}


WrongAnimal::WrongAnimal( string inputName ) : _type(inputName) {
	
	printColor(BOLD_HIGH_INTENSITY_YELLOW, "Random WrongAnimal has been created 🫥");
	extraLine();
}


WrongAnimal::WrongAnimal( const WrongAnimal& copy ){ *this = copy; }


WrongAnimal::~WrongAnimal( void ){

	printColor(BOLD_HIGH_INTENSITY_YELLOW, "WrongAnimal destroyed 💥");
	extraLine();
}


WrongAnimal& WrongAnimal::operator=( const WrongAnimal& right_operator ){
	
	if (this != &right_operator){
		
		this->_type = right_operator.getType();
	}
	return *this;
}


const string&	WrongAnimal::getType( void )const{ return this->_type; }


void	WrongAnimal::setType( const string& input){ this->_type = input; }

void WrongAnimal::makeSound( void )const{

	printColorNoEndl(RED, "THE WrongAnimal ");
	printColor(GREEN, "makes a sound ! Nobody knows what kind of sound, because this is an WrongAnimal");
}


ostream& operator<<( ostream& output_stream, const WrongAnimal& right_input ){
	
	output_stream << "Type of WrongAnimal Class = " << right_input.getType();
	return output_stream;
}