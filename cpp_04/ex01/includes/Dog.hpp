/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:07:01 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 15:35:08 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Dog : public Animal
{

private:


private:

	Brain *dogBrain;

protected:


public:

	Dog( void );
	Dog( string dogName );
	Dog( const Dog& copy );
	Dog& operator=( const Dog& right_operator );
	~Dog();

	void makeSound( void )const;
};

ostream& operator<<( ostream& output_stream, const Dog& input );


// ---------- Functions declarations ---------------



