/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:36:50 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 13:17:14 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"



int main( void ){

	// We'll declare a pointer to a new Animal.
	Animal *a1 = new Animal();

	
	// No surprise, a1 is an Animal, then it will make a sound from Aminal class.
	a1->makeSound();

	extraLine();
	
	// Let's declare now 2 Animal pointers which contains a cat, and another one for a dog.

	Animal *a2 = new Cat("Croquette");
	
	Animal *a3 = new Dog("Hercule");
	
	// makeSound is both a method from Animal AND Cat.
	a2->makeSound();
	
	// makeSound is both a method from Animal AND Dog.
	a3->makeSound();

	print("--------------------------------------------------------------");

	// Now let's make test from A WrongAnimal and WrongCat

	WrongAnimal *a4 = new WrongCat("Bad Cat");

	// Because base class has not been declared as virtual, despite a4 being a Cat, a4 will still displays WrongAnimal sound
	a4->makeSound();
	
	print("--------------------------------------------------------------");

	print("Destructors taking place");
	// Freeing memory from the allocated targeted
	// (explain virtual destructor)
	delete a1;
	delete a2;
	delete a3;
	delete a4;


	return 0;
}

// ! Bellow is the main given by the subject
/*
int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	// The main subject does not provide delete functions, so I did.
	delete meta;
	delete i;
	delete j;
}
*/