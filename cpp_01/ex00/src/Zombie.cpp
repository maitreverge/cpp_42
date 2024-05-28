/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:56:48 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 14:06:59 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ){}

Zombie::~Zombie( void ){
	std::cout << "Zombie Destroyed" << std::endl;
}

void Zombie::announce ( void ){
	std::cout << this->getName();
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName( void )const{
	return this->_name;
}

void Zombie::setName( std::string input){
	this->_name = input;
}

