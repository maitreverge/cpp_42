/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:51:43 by flverge           #+#    #+#             */
/*   Updated: 2024/05/11 11:23:55 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

int main(void)
{
	Sample instance1(42);
	Sample instance2(42);

	// ! Les deux premiers tests testent l'egalite physique (avec les addresses)
	if (&instance1 == &instance1)
		std::cout << "instance1 and instance1 are physically equal" << std::endl;
	else
		std::cout << "instance1 and instance1 are not physically equal" << std::endl;

	if (&instance1 == &instance2)
		std::cout << "instance1 and instance2 are physically equal" << std::endl;
	else
		std::cout << "instance1 and instance2 are not physically equal" << std::endl;

	// ! Les deux derniers tests testent l'egalite structurelle (avec les valeurs)
	if (instance1.compare(& instance1) == 0)
		std::cout << "instance1 and instance1 are structurally equal" << std::endl;
	else
		std::cout << "instance1 and instance1 are not structurally equal" << std::endl;

	if (instance1.compare(& instance2) == 0)
		std::cout << "instance 1 and instance2 are structurally equal" << std::endl;
	else
		std::cout << "instance 1 and instance2 are not structurally equal" << std::endl;
	
	return 0;
}