/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:38:55 by flverge           #+#    #+#             */
/*   Updated: 2024/06/23 12:44:08 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void){

	print("----------------- TEST 1 -----------------");
	{
		// When working with abstract class, we can still declare it as a pointer, it won't cause any problems.
		a_Animal *a1 = new Cat("Croquette", "Miam Miam");
		
		// However, it will cause problems in this case, because infine we still use a_Animal class
		// a_Animal *a2 = new a_Animal();

		cout << *a1 << endl;

		delete a1;
	}

	print("----------------- TEST 2 -----------------");
	{
		// Problems arrise when we want to declare a_Animal as a simple instace, it won't work.
		
		// ! Uncomment the bellow line to see error compilation
		// a_Animal a;

		
		// Others class must have the pure virtual method in a_Animal implemented as well,
		// Otherwise the derived class will also become abstract

		// Try to comment the method 
		Dog d1;
		Cat c1;
	}

	// a_Animal x;

	return 0;
}