/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:44:20 by flverge           #+#    #+#             */
/*   Updated: 2024/06/17 14:02:21 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:


public:

	ScavTrap( void );
	ScavTrap( const ScavTrap& copy );
	ScavTrap& operator=( const ScavTrap& right_operator );
	~ScavTrap();

};

ostream& operator<<( ostream& output_stream, const ScavTrap& input );


// ---------- Functions declarations ---------------


ScavTrap::ScavTrap( void ){}


ScavTrap::ScavTrap( const ScavTrap& copy ){ *this = copy; }


ScavTrap::~ScavTrap( void ){}


ScavTrap& ScavTrap::operator=( const ScavTrap& right_operator ){
	if (this != &right_operator){
		// Reassign every value with the getter value 
		// this->_foo = right_operator.getFoo()
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const ScavTrap& right_input ){
	//output_stream << right_input.PutAGetterFunctionhere();
	return output_stream;
}
