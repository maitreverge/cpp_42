/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:08:53 by flverge           #+#    #+#             */
/*   Updated: 2024/05/27 12:10:07 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main( void ){

	Phonebook phonebook;
	std::string menuPrompt;

	welcomePrinting("1982 PhoneBook");

	while (1)
	{
		do
		{
			pleasePrompt();
			getline(std::cin, menuPrompt);
		} while (!validMenuPrompt(menuPrompt));
		
		if (menuPrompt == "ADD")
		{
			
		}
		else if (menuPrompt == "SEARCH")
		{
			
		}
		else // EXIT
			definiveExit();
	}
	return 0;
}