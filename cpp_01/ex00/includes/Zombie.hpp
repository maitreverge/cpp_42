/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:56:55 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 14:32:29 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

// ANSII colors codes
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

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
