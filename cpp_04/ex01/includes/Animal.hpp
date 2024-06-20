/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:37:17 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 15:30:25 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"

class Animal
{

private:

	
protected:

	string _type;

public:

	Animal( void );
	Animal( string inputName );
	Animal( const Animal& copy );
	Animal& operator=( const Animal& right_operator );
	virtual ~Animal();

	const string&	getType( void )const;
	void			setType( const string& input);

	virtual void makeSound( void )const;
};

ostream& operator<<( ostream& output_stream, const Animal& input );