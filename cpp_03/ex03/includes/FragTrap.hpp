/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:45:06 by flverge           #+#    #+#             */
/*   Updated: 2024/06/18 12:15:59 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:

	FragTrap( void );

public:

	FragTrap( string nameInput );
	FragTrap( const FragTrap& copy );
	FragTrap& operator=( const FragTrap& right_operator );
	~FragTrap();
	
	void highFivesGuys( void );

};

ostream& operator<<( ostream& output_stream, const FragTrap& input );