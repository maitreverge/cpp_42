/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:28:47 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 19:28:50 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"


Cat::Cat( void )
	: Animal( "" ), catBrain(new Brain()) {

	printColor(GREEN, "Cat has been created 🐈");
}

Cat::Cat( string catName )
	: Animal( catName ), catBrain(new Brain()) {

	printColor(GREEN, catName+" Cat has been created 🐈");
	extraLine();
}

Cat::Cat( const Cat& copy ) : Animal( copy ) { *this = copy; }

Cat::~Cat( void ){

	delete catBrain;
	printColor(GREEN, "Cat destroyed 😿");
	extraLine();
}

void Cat::makeSound( void )const{

	printColorNoEndl(RED, "THE CAT ");
	printColor(GREEN, "meows 😺");
}

const string& Cat::getThoughts( void )const{

	return this->catBrain->printIdea(); // method for proving deep copy
}



Cat& Cat::operator=( const Cat& right_operator ){

	if (this != &right_operator){
		
		this->_type = right_operator.getType();
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const Cat& right_input ){

	output_stream << "Type of Cat Class = " << right_input.getType();
	output_stream << "\nThoughts of the cat = " << right_input.getThoughts(); // proving for deep copy
	return output_stream;
}
