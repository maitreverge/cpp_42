/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instrument.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:21:29 by flverge           #+#    #+#             */
/*   Updated: 2024/06/19 16:16:15 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using std::cout;
using std::endl;

/*
! When a class only have abstract methods, this is called an interface

! The interface will serve as a blueprint for other users

! IMPORTANT : An interface can't have other attributes

*/
class Instrument{

public:
	// virtual void makeSound( void ){ cout << "Instrument makes sound" << endl;}
	// void makeSound( void ){ cout << "Instrument makes sound" << endl;}
	virtual void makeSound( void ) = 0;
};

class Guitar : public Instrument
{
	public:

	void makeSound( void ){ cout << "Guitar Make Sound" << endl;}
};

class Piano : public Instrument
{
	void sayHello( void ){ cout << "Hello from Piano" << endl; }

	void makeSound( void ){ cout << "Piano playin" << endl; }
};

int main(void){

	Instrument i1;

	i1.makeSound();

	Guitar g1;

	g1.makeSound();

	Instrument *i2 = new Guitar;

	cout << "Instrument *i2 make sound function = " << endl;
	i2->makeSound(); // the output will depend f the base method is virtual or not

	Instrument *i3 = new Piano;

	// ! Abstract class can't be instacied 
	
	Instrument i5;

	delete i2; 
}