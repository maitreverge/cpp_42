/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:44:03 by flverge           #+#    #+#             */
/*   Updated: 2024/05/11 11:53:08 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

Sample::Sample(void) : foo(0)
{
	std::cout << "Constructor Called" << std::endl;

	return ;
}

Sample::~Sample(void)
{
	std::cout << "Destructor Called" << std::endl;

	return ;
}

void Sample::bar(void) const
{
	std::cout << "member function bar called" << std::endl;

	return ;	
}

