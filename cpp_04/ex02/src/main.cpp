/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:38:55 by flverge           #+#    #+#             */
/*   Updated: 2024/06/21 20:03:14 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void){

	// Test for basic printing a Animal with << operator overload
	print("----------------- TEST 1 -----------------");
	{
		Animal *a1 = new Cat("Croquette", "Miam Miam");

		cout << *a1 << endl;

		delete a1;
	}

	print("------------------ TEST 2----------------");
	{
		Animal *a2 = new Cat("Croquette", "Miam Miam");


		// Actually prints the adress of a1
		cout << a2 << endl;

		// Deferencing the pointer actually call the << Operator overload from Animal Class
		cout << *a2 << endl;
		print("----------------------------------");
		
		// Since a2 is a Cat, we would want to display Cat casting it something like
		
		// cout << (Cat)*a2 << endl;

		// Unfortunatelly, this is a wrong syntax, for this we should use dynamic casting

		// Because a2 is a pointer, straight casting it will still display the adress.
		
		cout << dynamic_cast<Cat*>(a2) << endl;
		
		print("----------------------------------");
		
		// We need then to deference the whole thing with * operator first.
		cout << *dynamic_cast<Cat*>(a2) << endl;

		delete a2;
	}

	print("------------------ TEST 3----------------");
	// Tests asked by the subject
	{
		Animal *animals[10];

		// Init first half with Cats
		for (size_t i = 0; i < 5; i++)
			animals[i] = new Cat("Miaous", "Croquette 100\% poisson ");

		// Init second half with Dogs
		for (size_t i = 5; i < 10; i++)
			animals[i] = new Dog("Roberto", "Croquette 100% Boeuf");
		
		print("----------------------------------");
		
		// Printing dynamically each Cat
		for (size_t i = 0; i < 5; i++)
			cout << *dynamic_cast<Cat*>(animals[i]) << endl;
		
		// Printing dynamically each Dog
		for (size_t i = 5; i < 10; i++)
			cout << *dynamic_cast<Dog*>(animals[i]) << endl;

		// Freeing each Animal
		for (size_t i = 0; i < 10; i++)
			delete animals[i];
			
	}

	return 0;
}