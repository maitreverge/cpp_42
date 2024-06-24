/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:44:03 by flverge           #+#    #+#             */
/*   Updated: 2024/05/11 11:05:53 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor Called" << std::endl;

	this->setFoo(0);
	std::cout << "this->getFoo(): " << this->getFoo() << std::endl;

	return ;
}

Sample::~Sample(void)
{
	std::cout << "Destructor Called" << std::endl;

	return ;
}

int Sample::getFoo(void) const
{
	return this->_foo;
}

void Sample::setFoo(int v)
{
	/*
	 Cet accesseur permet d'exercer un controle, ici de permettre 
	 de savoir si la valuer envoyee par l'utilisateur est bien positive
	*/
	
	if (v >= 0)
		this->_foo = v;
	
	return ;
}