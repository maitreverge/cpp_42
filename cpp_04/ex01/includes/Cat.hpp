/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:08:31 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 15:34:57 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Cat : public Animal
{

private:

	Brain *catBrain;

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