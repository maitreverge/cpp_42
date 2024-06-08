/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:18 by flverge           #+#    #+#             */
/*   Updated: 2024/06/08 08:58:11 by flverge          ###   ########.fr       */
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
	Fixed( const Fixed& copy );
	Fixed& operator=( const Fixed& right_operator);
	~Fixed();

	const int& getFixedPointValue( void )const;

};

ostream& operator<<( ostream& output_stream, const Fixed& input );


// ---------- Functions declarations ---------------



