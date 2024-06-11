/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:51:20 by flverge           #+#    #+#             */
/*   Updated: 2024/06/11 12:09:30 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point( void ) :
	x(Fixed(0)), y(Fixed(0)){}

Point::Point( const float inputX, const float inputY ):
	x(Fixed(inputX)), y(Fixed(inputY)){}

Point::Point( const Point& copy ){ *this = copy; }


Point::~Point( void ){}


const Fixed& Point::getFixedX( void )const{
	return this->x;
}


const Fixed& Point::getFixedY( void )const{
	return this->y;
}


Point& Point::operator=( const Point& right_operator ){
	(Fixed)x = right_operator.x.getFixedPointValue();
	(Fixed)y = right_operator.y.getFixedPointValue();
	return *this;
}


ostream& operator<<( ostream& output_stream, const Point& right_input ){
	output_stream << "Value of X = " << right_input.getFixedX().getFixedPointValue() << endl;
	output_stream << "Value of Y = " << right_input.getFixedY().getFixedPointValue() << endl;
	return output_stream;
}