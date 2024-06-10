/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:18 by flverge           #+#    #+#             */
/*   Updated: 2024/06/10 16:41:43 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_template.hpp"

class Fixed
{
private:
	
	int _fixedPointValue;
	static const int _fractionalBits = 8; 

public:

	Fixed( void );
	Fixed( const int intInput );
	Fixed( const float floatInput );
	Fixed( const Fixed& copy );
	Fixed& operator=( const Fixed& right_operator );
	~Fixed();

	// Operateurs de comparaison
	bool operator<( const Fixed& right_operator );
	bool operator<=( const Fixed& right_operator );
	bool operator>( const Fixed& right_operator );
	bool operator>=( const Fixed& right_operator );
	bool operator==( const Fixed& right_operator );
	bool operator!=( const Fixed& right_operator );

	// Operateurs arithmetiques
	Fixed operator+( const Fixed& right_operator );
	Fixed operator-( const Fixed& right_operator );
	Fixed operator*( const Fixed& right_operator );
	Fixed operator/( const Fixed& right_operator );
	
	// Operateurs d'incrementation
	Fixed&	operator++( void );
	Fixed	operator++( int ) ;
	Fixed&	operator--( void );
	Fixed	operator--( int );

	// Static functions min and max
	static Fixed&		min( Fixed& nb1, Fixed& nb2);
	static const Fixed&	min( const Fixed& nb1, const Fixed& nb2);
	static Fixed&		max( Fixed& nb1, Fixed& nb2);
	static const Fixed&	max( const Fixed& nb1, const Fixed& nb2);

	// Others member functions
	const int&	getFixedPointValue( void )const;
	float		toFloat( void )const;
	int			toInt( void )const;

};

ostream& operator<<( ostream& output_stream, const Fixed& input );