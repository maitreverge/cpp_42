/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:18 by flverge           #+#    #+#             */
/*   Updated: 2024/06/08 16:40:47 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_template.hpp"

class Fixed
{
private:
	
	int _fixedPointValue;
	static const int _fractionalBits = 8; 

public:

	Fixed( void ); // done
	Fixed( const int intInput ); // done
	Fixed( const float floatInput ); // done
	Fixed( const Fixed& copy ); // done
	Fixed& operator=( const Fixed& right_operator ); // done
	~Fixed(); // done

	// Operateurs de comparaison
	bool operator<( const Fixed& right_operator ); // done
	bool operator<=( const Fixed& right_operator ); // done
	bool operator>( const Fixed& right_operator ); // done
	bool operator>=( const Fixed& right_operator ); // done
	bool operator==( const Fixed& right_operator ); // done
	bool operator!=( const Fixed& right_operator ); // done

	// Operateurs arithmetiques
	Fixed operator+( const Fixed& right_operator );
	Fixed operator-( const Fixed& right_operator );
	Fixed operator*( const Fixed& right_operator );
	Fixed operator/( const Fixed& right_operator ); // ! Div by zero edge case
	
	// Operateurs d'incrementation
	Fixed operator++( void );
	Fixed operator++( int ) ;
	Fixed operator--( void );
	Fixed operator--( int );

	static Fixed& min( Fixed& nb1, Fixed& nb2);
	static const Fixed& min( const Fixed& nb1, const Fixed& nb2);
	static Fixed& max( Fixed& nb1, Fixed& nb2);
	static const Fixed& max( const Fixed& nb1, const Fixed& nb2);

	// Others member functions
	const int&	getFixedPointValue( void )const;
	float		toFloat( void )const;
	int			toInt( void )const;

};

ostream& operator<<( ostream& output_stream, const Fixed& input );


// ---------- Functions declarations ---------------



