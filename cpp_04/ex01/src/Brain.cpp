/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:32:11 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 15:57:03 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"


Brain::Brain( void ){

	printColor(CYAN, "A Brain was created 🧠");
}


Brain::Brain( const Brain& copy ){ *this = copy; }


Brain::~Brain( void ){

	printColor(CYAN, "A Brain was destroyed 🧠");
}


Brain& Brain::operator=( const Brain& right_operator ){

	if (this != &right_operator){
		
		
	}
	return *this;
}