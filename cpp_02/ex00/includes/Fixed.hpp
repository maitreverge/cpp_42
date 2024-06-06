/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:18 by flverge           #+#    #+#             */
/*   Updated: 2024/06/05 14:27:47 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_template.hpp"

class Fixed
{
private:
	int fixedPoint;
	static const int fractionalBits = 8;
public:
	Fixed( void ); // default constructor
	Fixed( const Fixed& copy  ); //  Copy constructor
	Fixed& operator=(const Fixed& rhs); // Copy assignment operator overload
	~Fixed(); // destructor

	void	setRawBits( int const raw );
	int		getRawBits( void ) const;
};