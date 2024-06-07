/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:18 by flverge           #+#    #+#             */
/*   Updated: 2024/06/07 14:51:32 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

class Fixed
{
private:

	int _fixedPointValue;
	static const int _fractionalBits = 8; 

public:

	Fixed ( void );
	
	// Constructors
	Fixed( const int intInput );
	Fixed( const float floatInput );
	Fixed( const Fixed& copy ); // Copy constructor
	
	// Destructors
	~Fixed();
	
	// Class assignment operator overload
	Fixed& operator=( const Fixed& right_operator);
	
	// Getter fromthe subject
	float	toFloat( void ) const;
	int		toInt( void ) const;

};