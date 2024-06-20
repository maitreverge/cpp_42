/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:38:55 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 15:59:46 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

int main(void){

	Animal *a1 = new Cat("Croquette");

	a1->makeSound();

	delete a1;

	
	return 0;
}