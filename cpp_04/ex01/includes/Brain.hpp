/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:40:11 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 15:34:53 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Brain
{

private:

	// Some private members

protected:
	
	Brain( void );
	Brain( const Brain& copy );
	~Brain();
	Brain& operator=( const Brain& right_operator );
	
	string ideas[100];

	friend class Cat;
	friend class Dog;

public:

	// constructeur avec une string

};



// ---------- Functions declarations ---------------


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