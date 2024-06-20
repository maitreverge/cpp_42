/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:40:11 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 19:28:59 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Brain
{

private:

	// Some private members

protected:
	
	
	string ideas[100];

	// friend class Cat;
	// friend class Dog;

public:

	Brain( void );
	Brain( string ideaInput );
	Brain( const Brain& copy );
	~Brain();
	Brain& operator=( const Brain& right_operator );

	const string& printIdea( void )const; 

};