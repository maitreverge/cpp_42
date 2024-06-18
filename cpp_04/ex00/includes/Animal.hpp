/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:37:17 by flverge           #+#    #+#             */
/*   Updated: 2024/06/18 22:07:20 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
#include "Dog.hpp"

class Animal
{

protected:

	string _type;
	void makeSound( void )const;

public:

	Animal( void );
	Animal( const Animal& copy );
	Animal& operator=( const Animal& right_operator );
	~Animal();

	const string&	getType( void )const;
	void			setType( const string& input);

};

ostream& operator<<( ostream& output_stream, const Animal& input );


// ---------- Functions declarations ---------------


Animal::Animal( void ){}


Animal::Animal( const Animal& copy ){ *this = copy; }


Animal::~Animal( void ){}

const string&	Animal::getType( void )const{ return this->_type; }

void	Animal::setType( const string& input){ this->_type = input; }


Animal& Animal::operator=( const Animal& right_operator ){
	
	if (this != &right_operator){
		
		this->_type = right_operator.getType();
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const Animal& right_input ){
	
	output_stream << "Type of Animal Class = " << right_input.getType();
	return output_stream;
}
