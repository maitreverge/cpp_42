/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:48:24 by flverge           #+#    #+#             */
/*   Updated: 2024/06/11 11:47:16 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

int main ( void ){

	Point const a(0, 10);
    Point const b(-5, 0);
    Point const c(5, 0);

    // Points inside the triangle
    Point const inside1(0, 5);
    Point const inside2(-1, 2);
    Point const inside3(2, 3);

    // Points outside the triangle
    Point const outside1(0, 11);
    Point const outside2(-6, 0);
    Point const outside3(6, -1);

    // Points on the edges of the triangle
    Point const onEdge1(0, 0);  // on edge AB
    Point const onEdge2(-2.5, 5);  // on edge AC
    Point const onEdge3(2.5, 5);  // on edge BC

	printColor(BOLD_GREEN, "Testing points inside the triangle");

	cout << "inside1: " << bsp(a, b, c, outside3) << "\n";
	cout << "inside1: " << (bsp(a, b, c, inside1) ? "Inside" : "Outside") << "\n";
	cout << "inside2: " << (bsp(a, b, c, inside2) ? "Inside" : "Outside") << "\n";
	cout << "inside3: " << (bsp(a, b, c, inside3) ? "Inside" : "Outside") << "\n";

	printColor(BOLD_RED, "Testing points Outside the triangle");
	
	cout << "outside1: " << (bsp(a, b, c, outside1) ? "Inside" : "Outside") << "\n";
	cout << "outside2: " << (bsp(a, b, c, outside2) ? "Inside" : "Outside") << "\n";
	cout << "outside3: " << (bsp(a, b, c, outside3) ? "Inside" : "Outside") << "\n";

	printColor(BOLD_YELLOW, "Testing points on the edge of the triangle");
	
	cout << "onEdge1: " << (bsp(a, b, c, onEdge1) ? "Inside" : "Outside") << "\n";
	cout << "onEdge2: " << (bsp(a, b, c, onEdge2) ? "Inside" : "Outside") << "\n";
	cout << "onEdge3: " << (bsp(a, b, c, onEdge3) ? "Inside" : "Outside") << "\n";
}