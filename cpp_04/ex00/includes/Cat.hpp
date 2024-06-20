/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:08:31 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 12:40:35 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{

private:


private:

	// Some private members

protected:


public:

	Cat( void );
	Cat( string catName );
	Cat( const Cat& copy );
	Cat& operator=( const Cat& right_operator );
	~Cat();

	void makeSound( void )const;
};

ostream& operator<<( ostream& output_stream, const Cat& input );