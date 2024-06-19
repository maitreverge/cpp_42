/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:37:17 by flverge           #+#    #+#             */
/*   Updated: 2024/06/19 22:01:18 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

class Animal
{

private:

	Animal( void ); // So the user can't call this one because I choosed it.
	
protected:

	string _type;
	virtual void makeSound( void )const;

public:

	Animal( string inputName = ""); // Can be something, or empty
	Animal( const Animal& copy );
	Animal& operator=( const Animal& right_operator );
	~Animal();

	const string&	getType( void )const;
	void			setType( const string& input);

};

ostream& operator<<( ostream& output_stream, const Animal& input );