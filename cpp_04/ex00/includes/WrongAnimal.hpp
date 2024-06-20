/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:03:29 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 13:09:13 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"


class WrongAnimal
{

private:

	
protected:

	string _type;

public:

	WrongAnimal( void );
	WrongAnimal( string inputName); // Can be something, or empty
	WrongAnimal( const WrongAnimal& copy );
	WrongAnimal& operator=( const WrongAnimal& right_operator );
	virtual ~WrongAnimal();

	const string&	getType( void )const;
	void			setType( const string& input);

	void makeSound( void )const;
};

ostream& operator<<( ostream& output_stream, const WrongAnimal& input );