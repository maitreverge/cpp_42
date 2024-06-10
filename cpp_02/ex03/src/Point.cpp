/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:51:20 by flverge           #+#    #+#             */
/*   Updated: 2024/06/10 22:54:14 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point( void ) :
	x(Fixed(0)), y(Fixed(0)){}

Point::Point( const float inputX, const float inputY ):
	x(Fixed(inputX)), y(Fixed(inputY)){}

Point::Point( const Point& copy ){ *this = copy; }


Point::~Point( void ){}


Point& Point::operator=( const Point& right_operator ){
	// if (this != &right_operator){
	// 	this->x = right_operator.x;
	// 	this->y = right_operator.y;
	// }
	// return *this;
	return Point((right_operator.x.getFixedPointValue()), (right_operator.y.getFixedPointValue()));
}


ostream& operator<<( ostream& output_stream, const Point& right_input ){
	//output_stream << right_input.PutAGetterFunctionhere();
	return output_stream;
}