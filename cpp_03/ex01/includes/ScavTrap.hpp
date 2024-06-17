/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:44:20 by flverge           #+#    #+#             */
/*   Updated: 2024/06/17 15:10:15 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

protected:

	void guardGate( void );

public:

	ScavTrap( void );
	ScavTrap( const ScavTrap& copy );
	ScavTrap& operator=( const ScavTrap& right_operator );
	~ScavTrap();

};

ostream& operator<<( ostream& output_stream, const ScavTrap& input );