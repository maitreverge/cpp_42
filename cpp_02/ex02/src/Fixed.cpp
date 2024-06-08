/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:22 by flverge           #+#    #+#             */
/*   Updated: 2024/06/08 16:40:40 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed( void ){}

Fixed::Fixed( const int intInput ){
	
	// Multiply input by 2^fractionalBits, so 256.
	this->_fixedPointValue = intInput * pow(2, this->_fractionalBits);
}

Fixed::Fixed( const float floatInput ){
	
	this->_fixedPointValue = static_cast<int>(roundf(floatInput * pow(2, this->_fractionalBits)));
}


Fixed::Fixed( const Fixed& copy ){ *this = copy; }


Fixed::~Fixed( void ){}


Fixed& Fixed::operator=( const Fixed& right_operator ){
	if (this != &right_operator){
		this->_fixedPointValue = right_operator._fixedPointValue;
	}
	return *this;
}

// Operateurs de comparaison

bool Fixed::operator<( const Fixed& right_operator ){
	
	return (this->_fixedPointValue < right_operator._fixedPointValue)
}

bool Fixed::operator<=( const Fixed& right_operator ){
	
	return (this->_fixedPointValue <= right_operator._fixedPointValue)
}

bool Fixed::operator>( const Fixed& right_operator ){
	
	return (this->_fixedPointValue > right_operator._fixedPointValue)
}

bool Fixed::operator>=( const Fixed& right_operator ){
	
	return (this->_fixedPointValue >= right_operator._fixedPointValue)
}

bool Fixed::operator==( const Fixed& right_operator ){
	
	return (this->_fixedPointValue == right_operator._fixedPointValue)
}

bool Fixed::operator!=( const Fixed& right_operator ){
	
	return (this->_fixedPointValue != right_operator._fixedPointValue)
}

// Operateurs arithmetiques

Fixed Fixed::operator+( const Fixed& right_operator ){
	
	return Fixed(this->_fixedPointValue + right_operator._fixedPointValue);
}

Fixed Fixed::operator-( const Fixed& right_operator ){
	
}

Fixed Fixed::operator*( const Fixed& right_operator ){
	
}

Fixed Fixed::operator/( const Fixed& right_operator ){
	
}


// Others member functions
const int& Fixed::getFixedPointValue( void )const{
	return this->_fixedPointValue;
}
float Fixed::toFloat( void )const{

	return static_cast<float>( this->_fixedPointValue / pow(2, this->_fractionalBits) );
}

int Fixed::toInt( void )const{
	
	return ( this->_fixedPointValue / pow(2, this->_fractionalBits) );
}

ostream& operator<<( ostream& output_stream, const Fixed& right_input ){
	//output_stream << right_input.PutAGetterFunctionhere();
	return output_stream;
}