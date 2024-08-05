/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_template.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:24:24 by flverge           #+#    #+#             */
/*   Updated: 2024/08/05 14:18:53 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/**
 * @brief Trim all whitespaces
 * 
 * @param str 
 * @return string 
 */
string trimWhitespace(const string& str) {
    // Copy the input string to a new string which will be trimmed
    string trimmed = str;

    // Find the first character position after leading whitespace
    string::size_type left = trimmed.find_first_not_of(" \t\n\r");

    // Find the last character position before trailing whitespace
    string::size_type right = trimmed.find_last_not_of(" \t\n\r");
    
    // If both 'left' and 'right' are not string::npos (indicating that the string is not all whitespace)
    if (left != string::npos && right != string::npos) {
        // Trim the string by taking a substring from 'left' to 'right'
        trimmed = trimmed.substr(left, right - left + 1);
    } else {
        // If the string is all whitespace, clear it
        trimmed.clear();
    }
    
    // Return the trimmed string
    return trimmed;
}