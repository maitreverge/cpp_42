/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:56:55 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 14:08:32 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Zombie
{
	public:
		Zombie( void );
		~Zombie( void );
		
		void		announce ( void );
		
		// Getter and Setter for _name
		std::string getName ( void )const;
		void		setName ( std::string input );

	private:
		std::string _name;
};

void	randomChump( std::string name);
Zombie* newZombie( std::string name);



