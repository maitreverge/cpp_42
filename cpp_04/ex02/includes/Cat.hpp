/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:08:31 by flverge           #+#    #+#             */
/*   Updated: 2024/06/21 09:04:37 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"


class Cat : public Animal
{

private:

	Brain *catBrain;

public:

	Cat( void );
	Cat( string catName, string brainIdea );
	Cat( const Cat& copy );
	Cat& operator=( const Cat& right_operator );
	~Cat();

	void makeSound( void )const;

	void displayThought( void )const;

	const string& getThoughts( void )const;

};

ostream& operator<<( ostream& output_stream, const Cat& input );