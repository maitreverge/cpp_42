/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 20:28:47 by flverge           #+#    #+#             */
/*   Updated: 2024/06/23 12:45:27 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"


Cat::Cat( void )
	: a_Animal( "" ), catBrain(new Brain("Empty Thoughts")) {

	printColor(GREEN, "Cat has been created 🐈");
}

Cat::Cat( string catName, string brainIdea )
	: a_Animal( catName ), catBrain(new Brain(brainIdea)) {

	printColor(GREEN, catName+" Cat has been created 🐈");
	extraLine();
}

Cat::Cat( const Cat& copy ) : a_Animal( copy ) { *this = copy; }

Cat::~Cat( void ){

	delete catBrain;
	printColor(GREEN, "Cat destroyed 😿");
	extraLine();
}

// Comment this methods for making the Cat Class abstract;
void Cat::makeSound( void )const{

	printColorNoEndl(RED, "THE CAT ");
	printColor(GREEN, "meows 😺");
}

void Cat::displayThought( void )const{

	print(this->catBrain->getIdea());
}

const string& Cat::getThoughts( void )const{

	return this->catBrain->getIdea();
}



Cat& Cat::operator=( const Cat& right_operator ){

	if (this != &right_operator){
		
		this->_type = right_operator.getType();
		
		// Step one, delete the old brain
		delete this->catBrain;

		// Step two, reassign the new brain
		// this->catBrain = right_operator.catBrain;
		this->catBrain = new Brain(*right_operator.catBrain);
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const Cat& right_input ){

	output_stream << "Type of Cat Class = " << right_input.getType();
	output_stream << "\nThoughts of the cat = " << right_input.getThoughts();
	return output_stream;
}
