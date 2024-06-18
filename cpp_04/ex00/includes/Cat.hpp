/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:08:31 by flverge           #+#    #+#             */
/*   Updated: 2024/06/18 22:08:59 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{

private:

	// Some private members

protected:

	// Some protected members

public:

	Cat( void );
	Cat( const Cat& copy );
	Cat& operator=( const Cat& right_operator );
	~Cat();

};

ostream& operator<<( ostream& output_stream, const Cat& input );


// ---------- Functions declarations ---------------


Cat::Cat( void ){}


Cat::Cat( const Cat& copy ){ *this = copy; }


Cat::~Cat( void ){}


Cat& Cat::operator=( const Cat& right_operator ){

	if (this != &right_operator){
		// Reassign every value with the getter value 
		// this->_foo = right_operator.getFoo()
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const Cat& right_input ){

	//output_stream << right_input.PutAGetterFunctionhere();
	return output_stream;
}
