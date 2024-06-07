/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:24 by flverge           #+#    #+#             */
/*   Updated: 2024/06/07 14:50:37 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// must use the `roundf` function from <cmath>

int main( void ){

	Fixed a;
	Fixed const b( 10 );
	
	Fixed const c( 42.42f );
	
	Fixed const d( b );
	
	a = Fixed( 1234.4321f );
	
	// cout << "a is " << a << endl;
	// cout << "b is " << b << endl;
	// cout << "c is " << c << endl;
	// cout << "d is " << d << endl;
	cout << "a is " << a.toInt() << " as integer" << endl;
	cout << "b is " << b.toInt() << " as integer" << endl;
	cout << "c is " << c.toInt() << " as integer" << endl;
	cout << "d is " << d.toInt() << " as integer" << endl;
	
	return 0;
}