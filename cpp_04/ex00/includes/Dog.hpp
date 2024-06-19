/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:07:01 by flverge           #+#    #+#             */
/*   Updated: 2024/06/19 22:01:59 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{

private:

	Dog( void );

private:

	// Some private members

protected:

	void makeSound( void )const;

public:

	Dog( string dogName );
	Dog( const Dog& copy );
	Dog& operator=( const Dog& right_operator );
	~Dog();

};

ostream& operator<<( ostream& output_stream, const Dog& input );


// ---------- Functions declarations ---------------



