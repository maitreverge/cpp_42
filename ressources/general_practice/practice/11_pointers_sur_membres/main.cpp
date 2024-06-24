/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:51:43 by flverge           #+#    #+#             */
/*   Updated: 2024/05/29 17:54:59 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

/*
	! Important :
	Les pointeurs sur les attributs ou les fonctions membre de classe
	ont besoin d'etre ensuite specifies a l'instance de classe vers lequel il pointe
*/

int main(void)
{
	Sample instance;

	
	// Declaration de pointeur classique
	Sample *instancep = &instance;

	// Pointeur sur attribut membre
	int		Sample::*p = NULL;

	// Pointeur sur fonction membre
	void	(Sample::*f)(void) const;

	p = &Sample::foo;

	std::cout << "Value of member foo : " << instance.foo << std::endl;	
	
	instance.*p = 21;
	std::cout << "Value of member foo : " << instance.foo << std::endl;	
	
	instancep->*p = 42;
	std::cout << "Value of member foo : " << instance.foo << std::endl;	

	f = &Sample::bar;

	(instance.*f)();
	(instancep->*f)();

	return 0;
	
}