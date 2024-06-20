/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:38:55 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 19:49:26 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

int main(void){

	Animal *a1 = new Cat("Croquette", "Miam Miam");

	// Animal *a2 = new Cat("Miaous", "Miaous oui la guerre");

	cout << *a1 << endl;

	// cout << *a2 << endl;

	
	delete a1;
	// delete a2;

	
	return 0;
}