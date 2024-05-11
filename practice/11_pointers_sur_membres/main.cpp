/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:51:43 by flverge           #+#    #+#             */
/*   Updated: 2024/05/11 11:58:07 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

int main(void)
{
	Sample instance;

	
	// Declaration de pointeur classique
	Sample *instancep = &instance;

	int		Sample::*p = NULL;
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