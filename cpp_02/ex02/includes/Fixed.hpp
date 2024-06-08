/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:18 by flverge           #+#    #+#             */
/*   Updated: 2024/06/08 22:07:37 by flverge          ###   ########.fr       */
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
	Fixed operator+( const Fixed& right_operator ); // done
	Fixed operator-( const Fixed& right_operator ); // done
	Fixed operator*( const Fixed& right_operator ); // done
	Fixed operator/( const Fixed& right_operator ); // done
	
	// Operateurs d'incrementation
	Fixed& operator++( void ); // done
	Fixed operator++( int ) ; // done
	Fixed& operator--( void ); // done
	Fixed operator--( int ); // done

	// Static functions min and max
	static Fixed& min( Fixed& nb1, Fixed& nb2); // done
	static const Fixed& min( const Fixed& nb1, const Fixed& nb2); // done
	static Fixed& max( Fixed& nb1, Fixed& nb2); // done
	static const Fixed& max( const Fixed& nb1, const Fixed& nb2); // done

	// Others member functions
	const int&	getFixedPointValue( void )const; // done
	float		toFloat( void )const; // done
	int			toInt( void )const; // done

};

ostream& operator<<( ostream& output_stream, const Fixed& input );


// ---------- Functions declarations ---------------



