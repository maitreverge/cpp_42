/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:22 by flverge           #+#    #+#             */
/*   Updated: 2024/06/07 17:20:48 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed( void ){
	
	printColor(GREEN, "✅ Default Constructor Called ✅");
}

Fixed::Fixed( const int intInput ){
	
	// Multiply input by 2^fractionalBits, so 256.
	this->_fixedPointValue = intInput * pow(2, this->_fractionalBits);

	printColor(BOLD_HIGH_INTENSITY_GREEN, "✅ Int Constructor Called ✅");
	
}

Fixed::Fixed( const float floatInput ){
	
	this->_fixedPointValue = static_cast<int>(roundf(floatInput * pow(2, this->_fractionalBits)));
	printColor(BOLD_GREEN, "✅ Float Constructor Called ✅");
}


Fixed::Fixed( const Fixed& copy ){
	
	printColor(UNDERLINE_GREEN, "✅ Copy Constructor Called ✅");
	*this = copy;
}

// Destructor
Fixed::~Fixed( void ){
	
	printColor(BOLD_RED, "❌ Destructor Called ❌");
}


Fixed& Fixed::operator=( const Fixed& right_operator ){
	
	printColor(YELLOW, "🔄 Copy assignment Operator Called 🔄");
	if (this != &right_operator){
		this->_fixedPointValue = right_operator._fixedPointValue;
	}
	return *this;
}

float Fixed::toFloat( void )const{

	return static_cast<float>( this->_fixedPointValue / pow(2, this->_fractionalBits) );
}

int Fixed::toInt( void )const{
	
	// std::cout << "Result power = " << pow(2, this->_fractionalBits) << std::endl;
	return ( this->_fixedPointValue / pow(2, this->_fractionalBits) );
}

const int& Fixed::getFixedPointValue( void )const{
	
	return this->_fixedPointValue;
}


// Surcharge d'operateur d'input
std::ostream& operator<<( std::ostream& output_stream, const Fixed& right_input ){
	
	// output_stream << /*std::fixed << */ std::setprecision(5) << right_input.toFloat();
	output_stream << right_input.toFloat();
	return output_stream;
}