/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_contact.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:52:47 by flverge           #+#    #+#             */
/*   Updated: 2024/05/15 12:48:13 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/**
 * @brief Print `+----------+`
 * 
 */
void	print_separators(void)
{
	for (int i = 0; i < 4; i++)
	{
		print_no_endl("+----------");
		if (i == 3)
		{
			std::cout << "+" << std::endl;
		}
	}
}

/**
 * @brief Print header for SEARCH tab
 * 
 */
void	title_print(void)
{
	print_no_endl("|   INDEX  ");
	print_no_endl("| 1st name ");
	print_no_endl("| lastname ");
	print_no_endl("| nick name|");
	std::cout << std::endl;
}

/**
 * @brief Display every contact detail.
 * - Right allign the string if string.lenght() < 10
 * - Prints it straight if lenght() == 10
 * - Print the first 9 chars + '.' if lenght() > 10
 * 
 * @param str 
 */
void	display_line_contact(std::string str)
{
	// int i = 0;
	int len_str = str.length();

	print_no_endl("|");
	
	if (len_str < MAX_WIDTH)
	{
		for (int i = 0; i < MAX_WIDTH - len_str; i++)
			std::cout << " ";
		std::cout << str;
	}
	else if (len_str == MAX_WIDTH)
		std::cout << str;
	else // + de 10
	{
		for (int i = 0; i < MAX_WIDTH - 1; i++)
			std::cout << str[i];
		std::cout << ".";
	}
}

/**
 * @brief Checks if the selected index is from `1` to `8` included
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool	is_valid_index(std::string str)
{
	if (str == "-1")
	{
		print_color(RED, "⛔ Selected Index is empty ⛔");
		return false;
	}
	else if (str == "1"
	or	str == "2"
	or	str == "3"
	or	str == "4"
	or	str == "5"
	or	str == "6"
	or	str == "7"
	or	str == "8")
		return true;
	print_color(RED, "⛔ Wrong index typed ⛔");
	return false;
}

/**
 * @brief Checks if the input is either `yes` or `no`
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool	is_yes_or_no(std::string str)
{
	if (str == "y"
	or	str == "n")
		return true;
	print_color(RED, "⛔ Wrong input typed ⛔");
	return false;
}

/**
 * @brief Print whole tab of contacts.
 * 
 * @param contact 
 */
void	print_whole_contacts(PhoneBook contact)
{
	for (int i = 0; i < NB_CONTACT; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!string_is_empty(*contact.contactAccess[i][j]))
			{
				if (i < 9 && j == 0)
					std::cout << "|         " << i + 1;
				else if ( i >= 10 && j == 0)
					std::cout << "|        " << i + 1;
				display_line_contact(*contact.contactAccess[i][j]);
				if (j == 2)
				{
					print_no_endl("|");
					std::cout << std::endl;
				}
			}
		}
	}
	print_separators();
}

/**
 * @brief Global searching contact variable
 * 
 * @param ptr 
 */
void	search_contact(PhoneBook *ptr)
{
	PhoneBook contact;

	contact = *ptr;

	clear_screen();

	welcoming_printing("SEARCH Contact Menu");
	
	// print 3 first lines
	print_separators();
	title_print();
	print_separators();

	if (string_is_empty(*contact.contactAccess[0][0]))
		std::cout << RED << "NO CONTACT TO DISPLAY" << RESET << std::endl;
	else
	{
		print_whole_contacts(contact);

		// Detailed printing
		std::string promptIndex;
		
		// ask for y/n
		do
		{
			print_color_no_endl(YELLOW, "Do you wish to display a specific contact ? ");
			print("(y/n)");
			std::cout << BOLD << YELLOW <<  "-----" << RESET << std::endl;
			getline(std::cin, promptIndex);
		} while (!is_yes_or_no(promptIndex));

		if (promptIndex == "n")
			return ;
		else // yes
		{
			// ask for index between 1 and 8 + checks if the index is not empty
			int indexToDisplay;
			do
			{
				print_color_no_endl(GREEN, "Please choose the index");
				print(" (ex: 2) ");
				std::cout << BOLD << YELLOW <<  "-----" << RESET << std::endl;
				getline(std::cin, promptIndex);
				indexToDisplay = promptIndex[0] - 1 - 48;
				if (string_is_empty(*contact.contactAccess[indexToDisplay][0]))
				{
					promptIndex = "-1";
				}
			} while (!is_valid_index(promptIndex));

			// print every contact detail on cout
			print_color_no_endl(MAGENTA, "First Name : ");
			print(*contact.contactAccess[indexToDisplay][0]);
			print_color_no_endl(MAGENTA, "Last Name : ");
			print(*contact.contactAccess[indexToDisplay][1]);
			print_color_no_endl(MAGENTA, "Nick Name : ");
			print(*contact.contactAccess[indexToDisplay][2]);
			print_color_no_endl(MAGENTA, "Phone Number : ");
			print(*contact.contactAccess[indexToDisplay][3]);
			print_color_no_endl(MAGENTA, "Darkest Secret : ");
			print(*contact.contactAccess[indexToDisplay][4]);
		}
	}
}