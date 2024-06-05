/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:22 by flverge           #+#    #+#             */
/*   Updated: 2024/06/05 14:28:59 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Default constructor
Fixed::Fixed( void ) {}

// Copy constructor
Fixed::Fixed( const Fixed& copy ){
	
}


Fixed::~Fixed() {}

void Fixed::setRawBits( int const raw ){
	this->fixedPoint= raw;
}

int Fixed::getRawBits( void )const{
	return this->fixedPoint;
}