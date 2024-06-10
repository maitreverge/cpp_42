/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:51:14 by flverge           #+#    #+#             */
/*   Updated: 2024/06/10 22:42:06 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
private:

	const Fixed x;
	const Fixed y;

public:

	Point( void );
	Point( const float inputX, const float inputY );
	Point( const Point& copy );
	Point& operator=( const Point& right_operator );
	~Point();

};

ostream& operator<<( ostream& output_stream, const Point& input );