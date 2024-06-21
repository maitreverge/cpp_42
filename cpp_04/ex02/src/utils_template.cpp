/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_template.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:24:24 by flverge           #+#    #+#             */
/*   Updated: 2024/06/20 15:35:47 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_template.hpp"

/**
 * @brief Print a string with a newline at the end.
 * 
 * @param str 
 */
void	print( const string& str ){
	
	cout << str << endl;
}

/**
 * @brief Prints a string without a newline at the end.
 * 
 * @param str 
 */
void	printNoEndl( const string& str ){
	
	cout << str;
}

/**
 * @brief Prints a string with an ANSII `COLOR` and a newline at the end.
 * 
 * @param COLOR 
 * @param str 
 */
void	printColor( string COLOR, const string& str ){
	
	cout << COLOR << str << RESET << endl;
}

/**
 * @brief Prints a string with an ANSII `COLOR` without a newline at the end.
 * 
 * @param COLOR 
 * @param str 
 */
void	printColorNoEndl( string COLOR, const string& str ){
	
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
void	customExit( const string& str ){
	
	printColor(RED, str);
	std::exit(EXIT_SUCCESS);
}

/**
 * @brief c++98 itoa implementation.
 * 
 * @param target 
 * @return string 
 */
string customItoA( const long long int& target ){

	string temp;
	stringstream out;
	
	out << target;
	temp = out.str();

	return temp;
}

/**
 * @brief c++98 atoi implementation.
 * 
 * @param str 
 * @return int 
 */
int customAtoI(const string& str) {
	
	int result;
	
	std::stringstream ss(str);
	ss >> result;
	
	if (ss.fail()) {
		customExit("customAtoI failed to allocate in stringstream");
	}
	return result;
}

/**
 * @brief Prints an extra empty line
 * 
 */
void	extraLine( void ){

	cout << endl;
}
