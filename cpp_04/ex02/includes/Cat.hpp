/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:08:31 by flverge           #+#    #+#             */
/*   Updated: 2024/06/23 12:45:16 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "a_Animal.hpp"
#include "Brain.hpp"


class Cat : public a_Animal
{

private:

	Brain *catBrain;

public:

	Cat( void );
	Cat( string catName, string brainIdea );
	Cat( const Cat& copy );
	Cat& operator=( const Cat& right_operator );
	~Cat();

	// Comment this methods for making the Cat class abstract
	void makeSound( void )const;

	void displayThought( void )const;

	const string& getThoughts( void )const;

};

ostream& operator<<( ostream& output_stream, const Cat& input );