/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:57:23 by flverge           #+#    #+#             */
/*   Updated: 2024/10/03 10:20:29 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utils_template.hpp"
class ICharacter;

class AMateria
{

protected:

	string _type;

public:

	AMateria( void );
	AMateria( const string &type );
	AMateria( const AMateria& copy );
	AMateria& operator=( const AMateria& right_operator );
	virtual ~AMateria();

	const string& getType() const;

	virtual AMateria* clone() const = 0;

	virtual void use(ICharacter& target);

};