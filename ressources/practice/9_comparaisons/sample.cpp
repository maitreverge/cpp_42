/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:44:03 by flverge           #+#    #+#             */
/*   Updated: 2024/05/11 11:13:50 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

Sample::Sample(int v) : _foo(v)
{
	std::cout << "Constructor Called" << std::endl;

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

int Sample::compare(Sample * other) const
{
	if (this->_foo < other->getFoo())
		return -1;
	else if (this->_foo > other->getFoo())
		return 1;

	return 0;
}