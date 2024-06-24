/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:51:43 by flverge           #+#    #+#             */
/*   Updated: 2024/05/11 11:05:20 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

int main(void)
{
	Sample instance;

	instance.setFoo(42);
	std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;

	instance.setFoo(-42);
	std::cout << "instance.getFoo() : " << instance.getFoo() << std::endl;

	return 0;

}