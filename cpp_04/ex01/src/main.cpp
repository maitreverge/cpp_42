/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:38:55 by flverge           #+#    #+#             */
/*   Updated: 2024/06/21 09:16:51 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

int main(void){

	// Animal *a1 = new Cat("Croquette", "Miam Miam");


	// a1->displayThought();

	// Animal a2 = *a1;

	// a2.displayThought();

	// cout << *a2 << endl;

	print("----------------------------------");

	Cat c1("Miaous", "Turbo Croquette");

	print("Cat 1 name = "+c1.getType());
	c1.displayThought();

	
	print("----------------------------------");

	Cat c2;
	
	c2 = c1;

	print("Cat 2 name = "+c2.getType());
	
	c2.displayThought();

	
	// delete a1;
	// delete a2;

	
	return 0;
}