/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:51:36 by flverge           #+#    #+#             */
/*   Updated: 2024/06/11 11:49:54 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

bool bsp( Point const& a, Point const& b, Point const& c, Point const& point){

	float v0x = c.getFixedX().getFixedPointValue() - a.getFixedX().getFixedPointValue(); // == 5 - 0
	
    float v0y = c.getFixedY().getFixedPointValue() - a.getFixedY().getFixedPointValue();
    float v1x = b.getFixedX().getFixedPointValue() - a.getFixedX().getFixedPointValue();
    float v1y = b.getFixedY().getFixedPointValue() - a.getFixedY().getFixedPointValue();
    float v2x = point.getFixedX().getFixedPointValue() - a.getFixedX().getFixedPointValue();
    float v2y = point.getFixedY().getFixedPointValue() - a.getFixedY().getFixedPointValue();

    float dot00 = v0x * v0x + v0y * v0y;
    float dot01 = v0x * v1x + v0y * v1y;
    float dot02 = v0x * v2x + v0y * v2y;
    float dot11 = v1x * v1x + v1y * v1y;
    float dot12 = v1x * v2x + v1y * v2y;

    float denom = dot00 * dot11 - dot01 * dot01;
    if (denom == 0)
		return false;

    float u = (dot11 * dot02 - dot01 * dot12) / denom;
    float v = (dot00 * dot12 - dot01 * dot02) / denom;

	if (u > 0 and v > 0 and u + v < 1)
		return true;
	return false;
}


/*

def is_point_in_triangle(px, py, ax, ay, bx, by, cx, cy):
    v1 = (cx - ax, cy - ay)
    v2 = (bx - ax, by - ay)
    v3 = (px - ax, py - ay)

    dot00 = v1[0] * v1[0] + v1[1] * v1[1]
    dot01 = v1[0] * v2[0] + v1[1] * v2[1]
    dot02 = v1[0] * v3[0] + v1[1] * v3[1]
    dot11 = v2[0] * v2[0] + v2[1] * v2[1]
    dot12 = v2[0] * v3[0] + v2[1] * v3[1]

    denom = dot00 * dot11 - dot01 * dot01
    u = (dot11 * dot02 - dot01 * dot12) / denom
    v = (dot00 * dot12 - dot01 * dot02) / denom

    return u >= 0 and v >= 0 and (u + v) <= 1


*/