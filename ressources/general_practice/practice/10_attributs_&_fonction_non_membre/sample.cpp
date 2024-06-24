/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:44:03 by flverge           #+#    #+#             */
/*   Updated: 2024/05/11 11:40:29 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor Called" << std::endl;
	Sample::_nbInst += 1;

	return ;
}

Sample::~Sample(void)
{
	std::cout << "Destructor Called" << std::endl;
	Sample::_nbInst -= 1;

	return ;
}

int Sample::getNbInst(void)
{
	// ! IMPORTANT :
	/*
	Quand la fonction est statique (donc non membre), le pointeur
	invisible de l'instance n'est pas passee en paramettre, donc
	On ne pourra pas utiliser le mot clef `this->`
	
	*/
	return Sample::_nbInst;
	// au lieu de this->_nbInst
}

int Sample::_nbInst = 0;