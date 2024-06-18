/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:07:01 by flverge           #+#    #+#             */
/*   Updated: 2024/06/18 22:09:07 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{

private:

	// Some private members

protected:

	// Some protected members

public:

	Dog( void );
	Dog( const Dog& copy );
	Dog& operator=( const Dog& right_operator );
	~Dog();

};

ostream& operator<<( ostream& output_stream, const Dog& input );


// ---------- Functions declarations ---------------


Dog::Dog( void ){}


Dog::Dog( const Dog& copy ){ *this = copy; }


Dog::~Dog( void ){}


Dog& Dog::operator=( const Dog& right_operator ){

	if (this != &right_operator){
		// Reassign every value with the getter value 
		// this->_foo = right_operator.getFoo()
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const Dog& right_input ){

	//output_stream << right_input.PutAGetterFunctionhere();
	return output_stream;
}
