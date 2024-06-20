/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:40:11 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 15:57:32 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Brain
{

private:

	// Some private members

protected:
	
	Brain( void );
	Brain( const Brain& copy );
	~Brain();
	Brain& operator=( const Brain& right_operator );
	
	string ideas[100];

	friend class Cat;
	friend class Dog;

public:

	// constructeur avec une string

};