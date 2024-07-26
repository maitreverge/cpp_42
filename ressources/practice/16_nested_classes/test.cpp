/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:10:58 by flverge           #+#    #+#             */
/*   Updated: 2024/07/01 10:10:07 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::endl;

class Animal // The class containig the other class is called the Enclosing Class
{
	
public:
	int x;

	Animal(int input) : x(input){};
	~Animal(){};
	int getX(){ return this->x; }
	
	class Leg
	{
	public:
		int y;
		Leg(int input) : y(input){}
		int getY(){ return this->y; }
		
	};

};

int main(void){

	Animal a1(6);

	Animal::Leg a1_leg(99);

	a1_leg.

	// a1.getX()
	cout << "X from Animal = " << a1.getX() << endl;

	cout << "Y from leg = " << a1_leg.getY() << endl;

}