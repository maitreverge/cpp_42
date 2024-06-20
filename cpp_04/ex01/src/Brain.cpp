/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:32:11 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 19:42:52 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"


Brain::Brain( void ){

	printColor(CYAN, "A Brain was created 🧠");
}

Brain::Brain( string ideaInput ){ // proof for deep copy

	this->ideas[0] = ideaInput;
}


Brain::Brain( const Brain& copy ){ *this = copy; }


Brain::~Brain( void ){

	printColor(CYAN, "A Brain was destroyed 🧠");
}

const string& Brain::getIdea( void )const{

	// method for proving deep copy
	return this->ideas[0];
}


Brain& Brain::operator=( const Brain& right_operator ){

	if (this != &right_operator){
		
		
	}
	return *this;
}