/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:09:22 by flverge           #+#    #+#             */
/*   Updated: 2024/10/03 10:22:06 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
#include "AMateria.hpp"

class Cure : public AMateria
{

public:

	Cure( void );
	Cure( const Cure& copy );
	Cure& operator=( const Cure& right_operator );
	~Cure();

	AMateria* clone() const;

	void use(ICharacter& target);


};

ostream& operator<<( ostream& output_stream, const Cure& input );


// ---------- Functions declarations ---------------



