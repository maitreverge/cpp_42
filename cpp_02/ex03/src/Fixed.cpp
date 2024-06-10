/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:22 by flverge           #+#    #+#             */
/*   Updated: 2024/06/10 16:25:27 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointValue(0){}

Fixed::Fixed( const int intInput ){
	
	// Multiply input by 2^fractionalBits, so 256.
	
	// this->_fixedPointValue = intInput < this->_fractionalBits;
	
	this->_fixedPointValue = intInput * pow(2, this->_fractionalBits);
}

Fixed::Fixed( const float floatInput ){
	
	this->_fixedPointValue = roundf(floatInput * pow(2, this->_fractionalBits));
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
	
	return (this->_fixedPointValue < right_operator._fixedPointValue);
}

bool Fixed::operator<=( const Fixed& right_operator ){
	
	return (this->_fixedPointValue <= right_operator._fixedPointValue);
}

bool Fixed::operator>( const Fixed& right_operator ){
	
	return (this->_fixedPointValue > right_operator._fixedPointValue);
}

bool Fixed::operator>=( const Fixed& right_operator ){
	
	return (this->_fixedPointValue >= right_operator._fixedPointValue);
}

bool Fixed::operator==( const Fixed& right_operator ){
	
	return (this->_fixedPointValue == right_operator._fixedPointValue);
}

bool Fixed::operator!=( const Fixed& right_operator ){
	
	return (this->_fixedPointValue != right_operator._fixedPointValue);
}

// Operateurs arithmetiques

Fixed Fixed::operator+( const Fixed& right_operator ){
	
	return Fixed(this->toFloat() + right_operator.toFloat());
}

Fixed Fixed::operator-( const Fixed& right_operator ){
	
	return Fixed(this->toFloat() - right_operator.toFloat());
}

Fixed Fixed::operator*( const Fixed& right_operator ){
	
	return Fixed(this->toFloat() * right_operator.toFloat());
}

Fixed Fixed::operator/( const Fixed& right_operator ){
	
	if (right_operator.toFloat())
		return Fixed(this->toFloat() / right_operator.toFloat());
	return Fixed(0); // handling edge case dividing by zero.
}

// Operateurs d'incrementation
Fixed& Fixed::operator++( void ){ // ++i
	this->_fixedPointValue++;
	
	return (*this);
}

Fixed Fixed::operator++( int ){ // i++
	Fixed temp(*this); // Make a copy of the result
	this->_fixedPointValue++; // Increment the current instance
	return temp; // returns the object before the incrementation
}

Fixed& Fixed::operator--( void ){ // --i
	this->_fixedPointValue--;
	
	return (*this);
}

Fixed Fixed::operator--( int ){ // i--
	Fixed temp(*this);
	this->_fixedPointValue--;
	return temp;
}

// Static functions min and max
Fixed& Fixed::min( Fixed& nb1, Fixed& nb2 ){
	
	return nb1._fixedPointValue < nb2._fixedPointValue ? nb1 : nb2;
}

const Fixed& Fixed::min( const Fixed& nb1, const Fixed& nb2 ){
	
	return nb1._fixedPointValue < nb2._fixedPointValue ? nb1 : nb2;
}

Fixed& Fixed::max( Fixed& nb1, Fixed& nb2 ){
	
	return nb1._fixedPointValue > nb2._fixedPointValue ? nb1 : nb2;
}

const Fixed& Fixed::max( const Fixed& nb1, const Fixed& nb2 ){
	
	return nb1._fixedPointValue > nb2._fixedPointValue ? nb1 : nb2;
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
	output_stream << right_input.toFloat();
	return output_stream;
}