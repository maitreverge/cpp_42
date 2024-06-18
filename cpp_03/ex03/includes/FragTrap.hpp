/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:45:06 by flverge           #+#    #+#             */
/*   Updated: 2024/06/18 11:53:49 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:

	FragTrap( void );

public:

	FragTrap( string nameInput );
	FragTrap( const FragTrap& copy );
	FragTrap& operator=( const FragTrap& right_operator );
	~FragTrap();
	
	void highFivesGuys( void );

};

ostream& operator<<( ostream& output_stream, const FragTrap& input );