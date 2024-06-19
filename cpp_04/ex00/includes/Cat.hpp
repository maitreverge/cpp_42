/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:08:31 by flverge           #+#    #+#             */
/*   Updated: 2024/06/19 22:01:37 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{

private:

	Cat( void );

private:

	// Some private members

protected:

	void makeSound( void )const;

public:

	Cat( string catName );
	Cat( const Cat& copy );
	Cat& operator=( const Cat& right_operator );
	~Cat();

};

ostream& operator<<( ostream& output_stream, const Cat& input );