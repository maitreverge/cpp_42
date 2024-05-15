/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printing.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:05:24 by flverge           #+#    #+#             */
/*   Updated: 2024/05/15 12:51:23 by flverge          ###   ########.fr       */
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
 * @brief Wrapper function for printing without a endl;
 * 
 * @param str 
 */
void	print_no_endl(std::string str)
{
	std::cout << str;
}

/**
 * @brief Print to `std::cout` with ANSII colors with a `std::endl`.
 * 
 * @param COLOR 
 * @param str 
 */
void	print_color(std::string COLOR, std::string str)
{
	std::cout << COLOR << str << RESET << std::endl;
}

/**
 * @brief Print to `std::cout` with ANSII colors without a`std::endl`.
 * 
 * @param COLOR 
 * @param str 
 */
void	print_color_no_endl(std::string COLOR, std::string str)
{
	std::cout << COLOR << str << RESET;
}

/**
 * @brief If the string is only whitespaces or empty, return `true`.
 * Else return false.
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool	string_is_empty(std::string str)
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

/**
 * @brief Wrapper printing function for code readibility
 * 
 * @param message 
 */
void	welcoming_printing(std::string message)
{
	std::cout << "Welcome to " << GREEN << message << RESET << std::endl;
}

/**
 * @brief Wrapper printing function for code readibility
 * 
 * @param message 
 */
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