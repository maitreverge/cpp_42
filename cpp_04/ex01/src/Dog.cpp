/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:07:48 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 15:35:27 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Dog::Dog( void ) : Animal( "" ){}

Dog::Dog( string dogName ) : Animal( dogName ){

	printColor(BLUE, dogName+" Dog has been created 🐕");
	extraLine();
}


Dog::Dog( const Dog& copy ) : Animal( copy ) {}

Dog::~Dog( void ){

	printColor(BLUE, "DOG destroyed 🥺");
	extraLine();
}

void Dog::makeSound( void )const{

	printColorNoEndl(RED, "THE DOG ");
	printColor(GREEN, "barks 🐶");
}


Dog& Dog::operator=( const Dog& right_operator ){

	if (this != &right_operator){
		
		this->_type = right_operator.getType();
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const Dog& right_input ){

	output_stream << "Type of Dog Class = " << right_input.getType();
	return output_stream;
}

