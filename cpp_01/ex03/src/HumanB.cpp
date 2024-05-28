/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:48 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 20:37:43 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

HumanB::HumanB(/* args */)
{
}

HumanB::~HumanB()
{
}

const std::string& HumanB::getName( void )const{
	return this->_name;
}

void HumanB::setName( std::string input){
	this->_name = input;
}