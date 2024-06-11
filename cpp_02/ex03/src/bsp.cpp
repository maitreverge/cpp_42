/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:51:36 by flverge           #+#    #+#             */
/*   Updated: 2024/06/11 11:20:54 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point){
	
	Point vectorOne(c.getFixedX().getFixedPointValue() - a.getFixedX().getFixedPointValue(),
                    c.getFixedY().getFixedPointValue() - a.getFixedY().getFixedPointValue());
                    
    Point vectorTwo(b.getFixedX().getFixedPointValue() - a.getFixedX().getFixedPointValue(),
                    b.getFixedY().getFixedPointValue() - a.getFixedY().getFixedPointValue());
                    
    Point vectorThree(point.getFixedX().getFixedPointValue() - a.getFixedX().getFixedPointValue(),
                      point.getFixedY().getFixedPointValue() - a.getFixedY().getFixedPointValue());

    float dot00 = vectorOne.getFixedX().getFixedPointValue() * vectorOne.getFixedX().getFixedPointValue() +
                  vectorOne.getFixedY().getFixedPointValue() * vectorOne.getFixedY().getFixedPointValue();

    float dot01 = vectorOne.getFixedX().getFixedPointValue() * vectorTwo.getFixedX().getFixedPointValue() +
                  vectorOne.getFixedY().getFixedPointValue() * vectorTwo.getFixedY().getFixedPointValue();

    float dot02 = vectorOne.getFixedX().getFixedPointValue() * vectorThree.getFixedX().getFixedPointValue() +
                  vectorOne.getFixedY().getFixedPointValue() * vectorThree.getFixedY().getFixedPointValue();

    float dot11 = vectorTwo.getFixedX().getFixedPointValue() * vectorTwo.getFixedX().getFixedPointValue() +
                  vectorTwo.getFixedY().getFixedPointValue() * vectorTwo.getFixedY().getFixedPointValue();

    float dot12 = vectorTwo.getFixedX().getFixedPointValue() * vectorThree.getFixedX().getFixedPointValue() +
                  vectorTwo.getFixedY().getFixedPointValue() * vectorThree.getFixedY().getFixedPointValue();

    float denominator = (dot00 * dot11) - (dot01 * dot01);

    if (denominator == 0)
        return false;

    float u = ((dot11 * dot02) - (dot01 * dot12)) / denominator;
    float v = ((dot00 * dot12) - (dot01 * dot02)) / denominator;

    return (u >= 0) && (v >= 0) && (u + v <= 1);
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