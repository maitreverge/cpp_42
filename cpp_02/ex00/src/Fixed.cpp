/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:22 by flverge           #+#    #+#             */
/*   Updated: 2024/06/06 16:18:51 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed( void ) : fixedPoint(0){
	
	printColor(BOLD_HIGH_INTENSITY_GREEN, "✅ Default Constructor Called ✅");
}

// Copy constructor
Fixed::Fixed( const Fixed& copy ){
	
	printColor(BOLD_GREEN, "✅ Copy Constructor Called ✅");
	this->fixedPoint = copy.getRawBits();
}

// Operator overload function
Fixed& Fixed::operator=( const Fixed& right_op ){

	printColor(BOLD_BLUE, "🔄 Copy Assignment Operator Called 🔄");
	
	this->fixedPoint = right_op.getRawBits();

	return *this;
}


Fixed::~Fixed(){
	
	printColor(BOLD_RED, "❌ Destructor Called ❌");
}

void Fixed::setRawBits( int const raw ){
	
	this->fixedPoint = raw;
}

int Fixed::getRawBits( void )const{
	
	printColor(BOLD_YELLOW, "✍️ getRawBits Member Function Called ✍️");
	return this->fixedPoint;
}