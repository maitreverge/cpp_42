/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printing.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:05:24 by flverge           #+#    #+#             */
/*   Updated: 2024/05/14 13:20:03 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/**
 * @brief Wrapper function for printing strings.
 * 
 * @param str 
 */
void	print(std::string str)
{
	std::cout << str << std::endl;
}

/**
 * @brief If the string is only whitespaces or empty, return `true`.
 * Else return false.
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool	stringIsEmpty(std::string str)
{
	if (str.empty())
		return true;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!isspace(str[i]))
			return false;
	}
	return true;
}

/**
 * @brief Wrapper function for clearing terminal
 * and moving the cursor up.
 * Uses ANSI escape codes to manipulate the terminal display.
 * 
 */
void clear_screen(void)
{
	std::cout << "\x1B[2J\x1B[H" << std::endl;
}

/**
 * @brief Exit message for eding PhoneBook program.
 * 
 */
void	custom_exit(void)
{
	clear_screen();
	std::cout << YELLOW << "Thanks for using PhoneBook 1982" << RESET << std::endl;
	exit(0);
}

/**
 * @brief Return `true` if the given string is either `ADD`, `SEARCH` or `EXIT`.
 * Return `false` otherwise.
 * 
 * @param prompt 
 * @return true 
 * @return false 
 */
bool	valid_prompt(std::string prompt)
{
	if (prompt == "EXIT"
	or	prompt == "ADD"
	or	prompt == "SEARCH")
		return true;
	return false;
}

void	welcoming_printing(std::string message)
{
	std::cout << "Welcome to " << GREEN << message << RESET << std::endl;
}

void	please_prompt(std::string message)
{
	if (message == "error")
		std::cout << RED << "⛔ Unrecognized Command ⛔" << RESET << std::endl;
	std::cout << "Please enter : ";
	std::cout << GREEN << "ADD, "<< RESET;
	std::cout << GREEN << "SEARCH"<< RESET;
	std::cout << " or ";
	std::cout << GREEN <<  "EXIT" << RESET << std::endl;
	std::cout << BOLD << YELLOW <<  "-----" << RESET << std::endl;
}