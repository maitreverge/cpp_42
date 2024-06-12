/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:42:15 by flverge           #+#    #+#             */
/*   Updated: 2024/06/12 12:07:02 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_template.hpp"

class ClapTrap
{
private:

	ClapTrap( void );
	string _name;
	size_t _hitPoints;
	size_t _energyPoints;
	size_t _attackdamage;
	
public:

	ClapTrap( string nameInput );
	ClapTrap( const ClapTrap& copy );
	ClapTrap& operator=( const ClapTrap& right_operator );
	~ClapTrap();

	void attack( const string& target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );

};

ostream& operator<<( ostream& output_stream, const ClapTrap& input );


// ---------- Functions declarations ---------------


ClapTrap::ClapTrap( void ){}

ClapTrap::ClapTrap( string nameInput) :
_name(nameInput), _hitPoints(10), _energyPoints(10), _attackdamage(0){}


ClapTrap::ClapTrap( const ClapTrap& copy ){ *this = copy; }


ClapTrap::~ClapTrap( void ){}


ClapTrap& ClapTrap::operator=( const ClapTrap& right_operator ){
	if (this != &right_operator){
		// Reassign every value with the getter value 
		// this->_foo = right_operator.getFoo()
	}
	return *this;
}


ostream& operator<<( ostream& output_stream, const ClapTrap& right_input ){
	//output_stream << right_input.PutAGetterFunctionhere();
	return output_stream;
}
