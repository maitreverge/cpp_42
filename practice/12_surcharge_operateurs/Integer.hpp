/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:46:47 by flverge           #+#    #+#             */
/*   Updated: 2024/06/05 15:05:18 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Integer
{
private:
	int _n;
public:
	Integer( int const input );
	~Integer( void );

	int	getValue( void )const;

	Integer& operator=( Integer const & right_operator);
	/*
	Une surcharge d'operateur binaire, comme l'operateur d'assignation =
	A besoin de deux parametres.
	OR une fonction de surcharge d'operateur (comme toutes les fonctions)
	prennent par default une instance de la classe courante par default (this->)
	Une fonction de surcharge d'operateur de type incrementation d'aura donc pas besoin de parametre supplementaire
	*/
	Integer& operator+( /* The left operator is then this-> */ Integer const & right_operator) const;
};

Integer::Integer( int const input ) : _n(input)
{
}

int Integer::getValue( void )const
{
	return this->_n;
}


Integer::~Integer()
{
}

Integer& Integer::operator=( Integer const& right_operator ){
	std::cout << "Assignation operator called from" << this->_n;

	std::cout << "to" << right_operator.getValue() << std::endl;

	this->_n = right_operator.getValue();

	return *this;
}

Integer Integer::operator+( Integer const& right_operator) const{
	std::cout << "addition operator called with " << this->_n;

	std::cout << "and" << right_operator.getValue() << std::endl;

	return Integer( this->_n + right_operator.getValue() );
}
