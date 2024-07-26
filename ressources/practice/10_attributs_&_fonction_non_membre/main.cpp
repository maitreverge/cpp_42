/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:51:43 by flverge           #+#    #+#             */
/*   Updated: 2024/05/11 11:39:18 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

void	f0(void)
{
	Sample instance2;
	
	std::cout << "Number of instances = " << Sample::getNbInst() << std::endl;

	return ;
}

void	f1(void)
{
	Sample instance1;

	std::cout << "Number of instances = " << Sample::getNbInst() << std::endl;

	f0();

	return ;
	
}

int main(void)
{
	std::cout << "Number of instances = " << Sample::getNbInst() << std::endl;
	f1();
	std::cout << "Number of instances = " << Sample::getNbInst() << std::endl;
}