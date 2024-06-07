/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:22 by flverge           #+#    #+#             */
/*   Updated: 2024/06/07 14:49:43 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed( void ){}

Fixed::Fixed( const int intInput ){
	
	// Multiply input by 2^fractionalBits, so 256.
	this->_fixedPointValue = intInput * pow(2, this->_fractionalBits);

	printColor(BOLD_HIGH_INTENSITY_GREEN, "✅ Int Constructor Called ✅");
	
}

Fixed::Fixed( const float floatInput ){
	
	this->_fixedPointValue = static_cast<int>(roundf(floatInput * pow(2, this->_fractionalBits)));
	printColor(BOLD_GREEN, "✅ Float Constructor Called ✅");
}


Fixed::Fixed( const Fixed& copy ){ *this = copy; }

// Destructor
Fixed::~Fixed( void ){
	
	printColor(BOLD_RED, "❌ Destructor Called ❌");
}


Fixed& Fixed::operator=( const Fixed& right_operator ){
	if (this != &right_operator){
		this->_fixedPointValue = right_operator._fixedPointValue;
	}
	return *this;
}

float Fixed::toFloat( void )const{
	return static_cast<float>( this->_fixedPointValue / pow(2, this->_fractionalBits) );
}

int Fixed::toInt( void )const{
	return ( this->_fixedPointValue / pow(2, this->_fractionalBits) );
}