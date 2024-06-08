/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:22 by flverge           #+#    #+#             */
/*   Updated: 2024/06/08 08:58:45 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed( void ){}


Fixed::Fixed( const Fixed& copy ){ *this = copy; }


Fixed::~Fixed( void ){}


Fixed& Fixed::operator=( const Fixed& right_operator ){
	if (this != &right_operator){
		// Reassign every value with the getter value 
		// this->_foo = right_operator.getFoo()
	}
	return *this;
}

const int& Fixed::getFixedPointValue( void )const{
	return this->_fixedPointValue;
}



ostream& operator<<( ostream& output_stream, const Fixed& right_input ){
	//output_stream << right_input.PutAGetterFunctionhere();
	return output_stream;
}