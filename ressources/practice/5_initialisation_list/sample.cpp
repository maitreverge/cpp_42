/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:38:30 by flverge           #+#    #+#             */
/*   Updated: 2024/05/09 09:51:21 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"

// /**
//  * @brief Construct a new Sample:: Sample object
//  * 
//  * This is the first way to assign manually pointers to class attributes
//  * (this is manually)
//  * 
//  * @param p1 
//  * @param p2 
//  * @param p3 
//  */
// Sample::Sample(char p1, int p2, float p3)
// {
// 	std::cout << "Constructor Called" << std::endl;
	
// 	this->a1 = p1;

// 	std::cout << "this->a1 = " << this->a1 << std::endl;

// 	this->a2 = p2;

// 	std::cout << "this->a2 = " << this->a2 << std::endl;
	
// 	this->a3 = p3;

// 	std::cout << "this->a3 = " << this->a3 << std::endl;

// 	return ;
// }

// ! This program won't compile, we got two constructors

/**
 * @brief This is the second way to make pointers assignations
 * Called initialization list
 * 
 */
Sample::Sample(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3)
{
	std::cout << "Constructor Called" << std::endl;

	std::cout << "this->a1 = " << this->a1 << std::endl;
	std::cout << "this->a2 = " << this->a2 << std::endl;
	std::cout << "this->a3 = " << this->a3 << std::endl;

	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor Called" << std::endl;
	return ;
}