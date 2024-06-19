/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:07:51 by flverge           #+#    #+#             */
/*   Updated: 2024/06/19 12:20:41 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Character
{
	public:
		
		virtual void sayHello( void ){ cout << "Hello from Character" << endl; }
};

class Warrior : public Character
{
	
	public:
	
		void sayHello( void ){ cout << "Hello from Warrior" << endl; }
};

int main(void){

	Warrior w1;

	w1.sayHello(); // if not specified, this is gonna be the hello from Warrior
	w1.Character::sayHello(); // Needs to be specified 

	Warrior *a = new Warrior;
	
	Character *b = new Warrior;

	/*
	In this example without the virtual keyword,
	The link will be determined at the compilation time.
	This means that even if b is a Warrior, it will be interpretted as a Character.
	
	*/
	a->sayHello(); // -> Hello from Warrior
	b->sayHello(); // -> Hello from Character

}