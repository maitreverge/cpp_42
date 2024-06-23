/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:07:01 by flverge           #+#    #+#             */
/*   Updated: 2024/06/23 12:12:29 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "a_Animal.hpp"
#include "Brain.hpp"

class Dog : public a_Animal
{

private:


private:

	Brain *dogBrain;

public:

	Dog( void );
	Dog( string dogName, string brainIdea );
	Dog( const Dog& copy );
	Dog& operator=( const Dog& right_operator );
	~Dog();

	void makeSound( void )const;

	void displayThought( void )const;

	const string& getThoughts( void )const;
};

ostream& operator<<( ostream& output_stream, const Dog& input );