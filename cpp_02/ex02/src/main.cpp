/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:24 by flverge           #+#    #+#             */
/*   Updated: 2024/06/10 16:40:26 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main( void ){
	
	Fixed a(5);
	
	Fixed const b( Fixed( 5.0f ) * Fixed( 2 ) );
	
	std::cout << "a = " << a << std::endl;
	
	std::cout << "b = " << b << std::endl;
	
	std::cout << "++a = " << ++a << std::endl;
	
	std::cout << "a = " << a << std::endl;
	
	std::cout << "a++ = " << a++ << std::endl;
	
	std::cout << "a = " << a << std::endl;
	
	std::cout << "--a = " << --a << std::endl;
	
	std::cout << "a = " << a << std::endl;
	
	std::cout << "a-- = " << a-- << std::endl;
	
	std::cout << "a = " << a << std::endl;
	

	if (a < b)
		printColor(GREEN, "A is less than B");
	else
		printColor(GREEN, "B is less than A");

	if (a <= b)
		printColor(GREEN, "A is less than or equal to B");
	else
		printColor(GREEN, "B is less than A");

	if (a > b)
		printColor(GREEN, "A is greater than B");
	else
		printColor(GREEN, "B is greater than or equal to A");

	if (a >= b)
		printColor(GREEN, "A is greater than or equal to B");
	else
		printColor(GREEN, "B is greater than A");

	if (a == b)
		printColor(GREEN, "A is equal to B");
	else
		printColor(GREEN, "A is not equal to B");

	if (a != b)
		printColor(GREEN, "A is not equal to B");
	else
		printColor(GREEN, "A is equal to B");
	
	
	Fixed c = a + b;
	std::cout << "A + B = " << c << std::endl;

	c = a - b;
	std::cout << "A - B = " << c << std::endl;

	c = a * b;
	std::cout << "A * B = " << c << std::endl;

	c = a / b;
	std::cout << "A / B = " << c << std::endl;

	
	
	
	std::cout << "Fixed::max( a, b ) =  " << Fixed::max( a, b ) << std::endl;
	
	std::cout << "a.max( a, b ) =" << a.max( a, b ) << std::endl;

	std::cout << "Fixed::min( a, b ) = " << Fixed::min( a, b ) << std::endl;
	
	std::cout << "b.min( a, b ) = " <<  b.min( a, b ) << std::endl;
	
	return (0);
}

/*
		! This is the main test from the subject

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	
	std::cout << ++a << std::endl;
	
	std::cout << a << std::endl;
	
	std::cout << a++ << std::endl;
	
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}

*/