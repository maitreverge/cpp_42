/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:32:11 by flverge           #+#    #+#             */
/*   Updated: 2024/06/21 19:32:19 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"


Brain::Brain( void ){

	printColor(CYAN, "A Brain was created 🧠");
}

Brain::Brain( string ideaInput ){

	this->ideas[0] = ideaInput;
}


Brain::Brain( const Brain& copy ){ *this = copy; }


Brain::~Brain( void ){

	printColor(CYAN, "A Brain was destroyed 🧠");
}

const string& Brain::getIdea( void )const{

	return this->ideas[0];
}


Brain& Brain::operator=( const Brain& right_operator ){

	if (this != &right_operator){
		
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = right_operator.ideas[i];
	}
	return *this;
}