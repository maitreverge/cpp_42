/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:31:07 by flverge           #+#    #+#             */
/*   Updated: 2024/05/09 10:45:57 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"

Sample::Sample(void)
{
	std::cout << GREEN "Constructor Called" RESET << std::endl;

	this->publicFoo = 42;

	std::cout << "publicFoo = " << this->publicFoo << std::endl;
	

	this->_privateFoo = 24;
	std::cout << "_privateFoo = " << this->_privateFoo << std::endl;

	this->publicBar();
	this->_privateBar();

	return ;
}

Sample::~Sample(void)
{
	std::cout << RED "Destructor Called" RESET << std::endl;

	return ;
}

void Sample::publicBar(void) const
{
	std::cout << "publicBar called\nHello from publicBar" << std::endl;

	return ;
}

void Sample::_privateBar(void) const
{
	std::cout << "_privateBar called\nHello from _privateBar" << std::endl;

	return ;
}