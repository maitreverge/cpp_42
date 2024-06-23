/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:37:17 by flverge           #+#    #+#             */
/*   Updated: 2024/06/23 12:10:45 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

class a_Animal
{

private:

	
protected:

	string _type;

public:

	a_Animal( void );
	a_Animal( string inputName );
	a_Animal( const a_Animal& copy );
	a_Animal& operator=( const a_Animal& right_operator );
	virtual ~a_Animal();

	const string&	getType( void )const;
	void			setType( const string& input);

	// Pure Virtual method, which turn the whole class into an abstract class
	virtual void makeSound( void )const = 0;

	virtual void displayThought( void )const;

};

ostream& operator<<( ostream& output_stream, const a_Animal& input );