/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:04:51 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 13:10:19 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

private:


private:

	// Some private members

protected:


public:

	WrongCat( void );
	WrongCat( string catName );
	WrongCat( const WrongCat& copy );
	WrongCat& operator=( const WrongCat& right_operator );
	~WrongCat();

	void makeSound( void )const;
};

ostream& operator<<( ostream& output_stream, const WrongCat& input );