/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_template.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:24:17 by flverge           #+#    #+#             */
/*   Updated: 2024/07/25 14:07:49 by ubuntu           ###   ########.fr       */
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
