/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcpp.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:45:53 by flverge           #+#    #+#             */
/*   Updated: 2024/05/27 12:12:23 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/**
 * @brief Prints `str` on `cout`
 * 
 * @param str 
 */
void	print( std::string str )
{
	std::cout << str << std::endl;
}

/**
 * @brief Prints `str` on `cout` without endl
 * 
 * @param str 
 */
void	printNoEndl( std::string str )
{
	std::cout << str;
}

/**
 * @brief Prints `str` on `cout` with `COLOR`
 * 
 * @param COLOR 
 * @param str 
 */
void	printColor( std::string COLOR, std::string str )
{
	std::cout << COLOR << str << RESET << std::endl;
}

/**
 * @brief Prints `str` on `cout` with `COLOR` without endl
 * 
 * @param COLOR 
 * @param str 
 */
void	printColorNoEndl( std::string COLOR, std::string str )
{
	std::cout << COLOR << str << RESET;
}

/**
 * @brief Clears the screen
 * 
 */
void clearScreen( void )
{
	std::cout << "\x1B[2J\x1B[H" << std::endl;
}

/**
 * @brief Exit the program
 * 
 */
void	definiveExit( void )
{
	clearScreen();
	std::cout << YELLOW << "Thanks for using PhoneBook 1982" << RESET << std::endl;
	std::exit(EXIT_SUCCESS);
}

/**
 * @brief Checks if the prompt is valid
 * 
 * @param prompt 
 * @return true 
 * @return false 
 */
bool	validMenuPrompt( std::string prompt )
{
	if (prompt == "EXIT"
	or	prompt == "ADD"
	or	prompt == "SEARCH")
		return true;
	std::cout << RED << "⛔ Unrecognized Command ⛔" << RESET << std::endl;
	return false;
}

/**
 * @brief Prints the welcome message with `message` in green
 * 
 * @param message 
 */
void	welcomePrinting( std::string message )
{
	std::cout << "Welcome to " << GREEN << message << RESET << std::endl;
}

/**
 * @brief Keep prompting the user until a valid command is entered
 * 
 * @param message 
 */
void	pleasePrompt( void )
{
	std::cout << "Please enter : ";
	std::cout << GREEN << "ADD, "<< RESET;
	std::cout << GREEN << "SEARCH"<< RESET;
	std::cout << " or ";
	std::cout << GREEN <<  "EXIT" << RESET << std::endl;
	std::cout << BOLD << YELLOW <<  "-----" << RESET << std::endl;
}