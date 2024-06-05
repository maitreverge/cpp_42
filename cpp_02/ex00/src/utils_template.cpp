/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_template.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:24:24 by flverge           #+#    #+#             */
/*   Updated: 2024/06/05 12:56:26 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_template.hpp"

/**
 * @brief Print a string with a newline at the end.
 * 
 * @param str 
 */
void	print( string str ){
	cout << str << endl;
}

/**
 * @brief Prints a string without a newline at the end.
 * 
 * @param str 
 */
void	printNoEndl( string str ){
	cout << str;
}

/**
 * @brief Prints a string with an ANSII `COLOR` and a newline at the end.
 * 
 * @param COLOR 
 * @param str 
 */
void	printColor( string COLOR, string str ){
	cout << COLOR << str << RESET << endl;
}

/**
 * @brief Prints a string with an ANSII `COLOR` without a newline at the end.
 * 
 * @param COLOR 
 * @param str 
 */
void	printColorNoEndl( string COLOR, string str ){
	cout << COLOR << str << RESET;
}

/**
 * @brief Clears the terminal screen.
 * 
 */
void clearScreen( void ){
	cout << "\x1B[2J\x1B[H" << endl;
}

/**
 * @brief Custom exit function that prints a string in red before exiting.
 * 
 */
void	customExit( void ){
	printColor(RED, str);
	std::exit(EXIT_FAILURE);
}