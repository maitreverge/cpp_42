/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:38:30 by flverge           #+#    #+#             */
/*   Updated: 2024/05/09 10:07:18 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class.hpp"

Sample::Sample(float const f) : pi(f), nb(42)
{
	/*
	! Lorsque l'on passe pi(f), on INITIALISE la valeur pi a la valuer passee dans le main
	Et on assigne pas cette valeur, car cela fait partie de la construction
	(et une constante ne peut etre assignee)
	*/
	std::cout << "Constructor Called" << std::endl;

	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor Called" << std::endl;
	return ;
}

void Sample::bar(void) const 
{
	std::cout << "this->pi = " << this->pi << std::endl;
	std::cout << "this->nb = " << this->nb << std::endl;
}