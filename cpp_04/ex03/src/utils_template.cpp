/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_template.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:24:24 by flverge           #+#    #+#             */
/*   Updated: 2024/10/03 13:25:04 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_template.hpp"

#include "../includes/utils_template.hpp"

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
 * @brief Prints an extra empty line
 * 
 */
void	extraLine( void ){

	cout << endl;
}

/**
 * @brief Return `true` if the given `fileName` exists,
 * Return `false` otherwise.
 * 
 * @param fileName 
 * @return true 
 * @return false 
 */
bool	doesFileExists( const string& fileName){

	FILE * fileStream;

	fileStream = fopen(fileName.c_str(), "r");

	if (fileStream != NULL){
		
		fclose(fileStream);
		return true;
	}
	return false;
}