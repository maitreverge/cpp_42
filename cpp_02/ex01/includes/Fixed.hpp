/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:18 by flverge           #+#    #+#             */
/*   Updated: 2024/06/07 17:26:19 by flverge          ###   ########.fr       */
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

	// Constructors
	Fixed ( void );
	Fixed( const int intInput );
	Fixed( const float floatInput );

	// Copy constructor
	Fixed( const Fixed& copy );
	
	// Destructors
	~Fixed();
	
	// Class assignment operator overload
	Fixed& operator=( const Fixed& right_operator );
	Fixed& operator[]( const Fixed& right_operator );
	
	// Getter
	const int& getFixedPointValue( void )const;
	
	// Getter fromthe subject
	float	toFloat( void ) const;
	int		toInt( void ) const;

};

// Surcharge operateur outpout pour la classe 
std::ostream& operator<<( std::ostream& output_stream, const Fixed& right_input );
