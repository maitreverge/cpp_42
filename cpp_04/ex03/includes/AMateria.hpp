/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:14:41 by flverge           #+#    #+#             */
/*   Updated: 2024/06/25 15:32:05 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
// #include "ICharacter.hpp"

class AMateria
{

protected:

	string _type;

public:

	AMateria( void );
	AMateria( const string& type ); // done
	AMateria( const AMateria& copy );
	AMateria& operator=( const AMateria& right_operator );
	virtual ~AMateria();

	const string& getType( void )const; // done

	virtual AMateria* clone( void ) const = 0; // virtual
	
	virtual void use( ICharacter& target );

};