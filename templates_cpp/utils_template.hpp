/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_template.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:24:17 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 12:48:26 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <sstream>
#include <cstdlib>


using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::stringstream;

#include "colors.hpp" // Includes all ANSII color codes

// Utils wrappers functions 
void	print( const string& str );
void	printNoEndl( const string& str );
void	printColor( string COLOR, const string& str );
void	printColorNoEndl( string COLOR, const string& str );
void	clearScreen( void );
void	customExit( const string& str );
string	customItoA( const long long int& target);
int 	customAtoI( const string& str );
void	extraLine( void );
