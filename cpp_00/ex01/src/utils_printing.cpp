/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printing.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:05:24 by flverge           #+#    #+#             */
/*   Updated: 2024/05/13 19:45:18 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void	custom_exit(void)
{
	std::cout << MAGENTA << "Thanks for using PhoneBook 1982" << RESET<< std::endl;
	exit(0);
}

bool	valid_prompt(std::string prompt)
{
	if (prompt == "EXIT"
	or	prompt == "ADD"
	or	prompt == "SEARCH")
		return true;
	return false;
}

void	welcoming_printing(void)
{
	std::cout << "Welcome to " << GREEN << "PhoneBook 1982" << RESET << std::endl;
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