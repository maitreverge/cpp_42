/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:07:48 by flverge           #+#    #+#             */
/*   Updated: 2024/06/21 19:36:32 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog( void )
	: Animal( "" ), DogBrain(new Brain("Empty Thoughts")) {

	printColor(GREEN, "Dog has been created 🐕");
}

Dog::Dog( string dogName, string brainIdea )
	: Animal( dogName ), DogBrain(new Brain(brainIdea)) {

	printColor(GREEN, dogName+" Dog has been created 🐕");
	extraLine();
}

Dog::Dog( const Dog& copy ) : Animal( copy ) { *this = copy; }

Dog::~Dog( void ){

	delete DogBrain;
	printColor(GREEN, "Dog destroyed 🥺");
	extraLine();
}

void Dog::makeSound( void )const{

	printColorNoEndl(RED, "THE DOG ");
	printColor(GREEN, "barks 🐕");
}

void Dog::displayThought( void )const{

	print(this->DogBrain->getIdea());
}

const string& Dog::getThoughts( void )const{

	return this->DogBrain->getIdea();
}



Dog& Dog::operator=( const Dog& right_operator ){

	if (this != &right_operator){
		
		this->_type = right_operator.getType();
		
		// Step one, delete the old brain
		delete this->dogBrain;

		// Step two, reassign the new brain
		// this->dogBrain = right_operator.dogBrain;
		this->dogBrain = new Brain(*right_operator.dogBrain);
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const Dog& right_input ){

	output_stream << "Type of Dog Class = " << right_input.getType();
	output_stream << "\nThoughts of the dog = " << right_input.getThoughts();
	return output_stream;
}

