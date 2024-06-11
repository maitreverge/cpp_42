/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:51:20 by flverge           #+#    #+#             */
/*   Updated: 2024/06/11 09:58:15 by flverge          ###   ########.fr       */
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
	// if (this != &right_operator){
	// 	this->x = right_operator.x;
	// 	this->y = right_operator.y;
	// }
	// return *this;
	// return Point((right_operator.x.getFixedPointValue()), (right_operator.y.getFixedPointValue()));
	(void)right_operator;
	return *this;
}


ostream& operator<<( ostream& output_stream, const Point& right_input ){
	output_stream << right_input.getFixedX().getFixedPointValue();
	output_stream << right_input.getFixedX().getFixedPointValue();
	return output_stream;
}