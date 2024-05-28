/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:51 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 20:43:51 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "HumanB.hpp"

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

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon( void );
		~Weapon( void );
		const std::string&	getType( void )const;
		void			setType( std::string input );
};

void	print( std::string str );
void	printNoEndl( std::string str );
void	printColor( std::string COLOR, std::string str );
void	printColorNoEndl( std::string COLOR, std::string str );
