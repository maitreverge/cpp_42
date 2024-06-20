/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:36:50 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 12:51:07 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"



int main( void ){

	// We'll declare a pointer to a new Animal.
	Animal *a1 = new Animal();

	
	// No surprise, a1 is an Animal, then it will make a sound from Aminal class.
	a1->makeSound();

	extraLine();
	
	// Let's declare now 2 Animal pointers which contains a cat, and another one for a dog.

	Animal *a2 = new Cat("Croquette");
	
	extraLine();
	
	Animal *a3 = new Dog("Hercule");
	
	extraLine();

	a2->makeSound();
	
	a3->makeSound();
	
	delete a1;
	delete a2;
	delete a3;


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