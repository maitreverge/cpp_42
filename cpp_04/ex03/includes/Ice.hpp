/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:09:22 by flverge           #+#    #+#             */
/*   Updated: 2024/10/03 10:23:26 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{

private:

	// Some private members

public:

	Ice( void );
	Ice( const Ice& copy );
	Ice& operator=( const Ice& right_operator );
	~Ice();

	AMateria* clone() const;

	void use(ICharacter& target);

};

ostream& operator<<( ostream& output_stream, const Ice& input );