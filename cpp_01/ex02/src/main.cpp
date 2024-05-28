/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:22 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 20:15:09 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// ANSII colors codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BOLD    "\033[1m"

int main ( void ){
	
	// Defining the main string
	std::string mainString = "HI THIS IS BRAIN";

	// This is a pointer
	std::string* stringPTR = &mainString;

	// This is a reference
	std::string& stringREF = mainString;

	// Print mainString adress
	std::cout << "The memory adress of the variable mainString is :" << std::endl;
	std::cout << RED BOLD << &mainString << std::endl << RESET << std::endl;

	// Print stringPTR adress
	std::cout << "The memory adress of the pointer stringPTR is :" << std::endl;
	std::cout << GREEN BOLD << &stringPTR << RESET << std::endl << std::endl;
	
	// Print stringREF adress
	std::cout << "The memory adress of the reference stringREF is :" << std::endl;
	std::cout << RED BOLD << &stringREF << RESET << std::endl << std::endl;

	// Print mainString content
	std::cout << "In the variable mainString, there is :" << std::endl;
	std::cout << YELLOW BOLD <<  mainString << RESET << std::endl << std::endl;
	
	// Print stringPTR by de-referencing content
	std::cout << "In the variable stringPTR, there is :" << std::endl;
	std::cout << YELLOW BOLD <<  *stringPTR << RESET << std::endl << std::endl;

	// Print stringREF content
	std::cout << "In the variable stringREF, there is :" << std::endl;
	std::cout << YELLOW BOLD <<  stringREF <<  RESET << std::endl << std::endl;

	return 0;
}