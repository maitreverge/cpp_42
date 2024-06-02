/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:51 by flverge           #+#    #+#             */
/*   Updated: 2024/06/02 12:27:01 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stddef.h>

// #include "HumanA.hpp"
// #include "HumanB.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cin;


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
		string _type;
	public:
		Weapon( string input );
		~Weapon( void );
		const string&	getType( void )const;
		void			setType( string input );
};

void	print( string str );
void	printNoEndl( string str );
void	printColor( string COLOR, string str );
void	printColorNoEndl( string COLOR, string str );
