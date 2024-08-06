/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_template.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:24:17 by flverge           #+#    #+#             */
/*   Updated: 2024/08/06 10:47:06 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// Includes all ANSII color codes
#include "colors.hpp"

// Libraries
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>

// Using keywords
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
using std::getline;
using std::map;

#define PIPE '|'
#define DOT '.'
#define HYPHEN '-'



// ---------------------  Templates functions  ---------------------

/**
 * @brief Prints an template object with an `endl`
 * 
 * @tparam T 
 * @param obj 
 */
template< typename T >
void	print( const T& obj ){
	
	cout << obj << endl;
}

/**
 * @brief Prints an template object with no `endl`.
 * 
 * @tparam T 
 * @param obj 
 */
template< typename T >
void	printNoEndl( const T& obj ){
	
	cout << obj;
}

/**
 * @brief Prints an template object with the ANSII `COLOR` code with an `endl`. 
 * 
 * @tparam T 
 * @param COLOR 
 * @param obj 
 */
template< typename T >
void	printColor( string COLOR, const T& obj){

	cout << COLOR << obj << RESET << endl;
}

/**
 * @brief Prints an template object with the ANSII `COLOR` code without an `endl`.
 * 
 * @tparam T 
 * @param COLOR 
 * @param obj 
 */
template< typename T >
void	printColorNoEndl( string COLOR, const T& obj ){

	cout << COLOR << obj << RESET;
}

//  ------------------ Functions prototypes ------------------ 
void	clearScreen( void );
void	customExit( const string& str );
void	extraLine( void );
bool	doesFileExists( const string& fileName);
string	trimWhitespace(const string& str);


//  ------------------ Parsing prototypes ------------------ 

int    convertDateToInt( string &str );
bool    isValidValue( string &str );
bool isInputZero( string &input );
bool    isValidDate( string &str );
bool    isInputValid( string &str );
bool isValidChar( string &input );
bool    isStringDigit( string &str );



