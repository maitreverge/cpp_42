/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_template.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:24:17 by flverge           #+#    #+#             */
/*   Updated: 2024/07/22 09:24:55 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <climits>
#include <iomanip>
#include <cfloat>


using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::stringstream;
using std::exception;

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
bool	doesFileExists( const string& fileName);
