/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:36:50 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 13:27:28 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"



int main( void ){

	extraLine();
	print("--------------------------------------------------------------");
	extraLine();
	
	// We'll declare a pointer to a new Animal.
	{	
		Animal *a1 = new Animal();
	
		
		// No surprise, a1 is an Animal, then it will make a sound from Aminal class.
		a1->makeSound();
		delete a1;
		
	}

	print("--------------------------------------------------------------");
	extraLine();
	
	// Let's declare now 2 Animal pointers which contains a cat, and another one for a dog.
	{
			
		Animal *a2 = new Cat("Croquette");
		
		Animal *a3 = new Dog("Hercule");
		
		// makeSound is both a method from Animal AND Cat.
		a2->makeSound();
		
		// makeSound is both a method from Animal AND Dog.
		a3->makeSound();


		delete a2;
		delete a3;
		
	}
	print("--------------------------------------------------------------");
	extraLine();

	// Now let's make test from A WrongAnimal and WrongCat
	{

		WrongAnimal *a4 = new WrongCat("Bad Cat");

		// Because base class makeSound method has not been declared as virtual, despite a4 being a Cat, a4 will still displays WrongAnimal sound
		a4->makeSound();
		
		delete a4;

	}
	return 0;
}