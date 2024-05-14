/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:25:28 by flverge           #+#    #+#             */
/*   Updated: 2024/05/14 21:07:46 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void	assign_adresses(PhoneBook *phoneBook, Contact *contact)
{
	for (int i = 0; i < NB_CONTACT ; i++)
	{
		phoneBook->contactAccess[i][0] = &contact->first_name[i];
		phoneBook->contactAccess[i][1] = &contact->last_name[i];
		phoneBook->contactAccess[i][2] = &contact->nick_name[i];
		phoneBook->contactAccess[i][3] = &contact->phone_number[i];
		phoneBook->contactAccess[i][4] = &contact->secret[i];
	}
}

void	add_sub_contact(std::string message, std::string *target)
{
	do
	{
		print(message);
		getline(std::cin, *target);
	} while (stringIsEmpty(*target));
	// std::cout << "MASTER CHECK !!!!! : " << target << std::endl;
}

void	add_contact(PhoneBook *ptr, int writeIndex)
{
	PhoneBook contact;

	contact = *ptr;
	
	// int indexFreeContact = 0;	
	clear_screen();

	welcoming_printing("ADD Contact Menu");

	print("Please enter contact details bellow : ");

	// finds next free contact
	// ! needs to point to the first one if everything full
	// for (int i = 0; *contact.contactAccess[i][0] != ""; i++)

	// if (!stringIsEmpty(*contact.contactAccess[7][0]))
	// 	indexFreeContact = 0;
	// else
	// {
	// 	for (int i = 0; !stringIsEmpty(*contact.contactAccess[i][0]); i++) // segfault
	// 		indexFreeContact++;
	// }

	
	add_sub_contact("First Name : ", &*contact.contactAccess[writeIndex][0]);
	// std::cout << "PRINT CHECK" << *contact.contactAccess[indexFreeContact][0] << std::endl;
	add_sub_contact("Last Name : ", &*contact.contactAccess[writeIndex][1]);
	// std::cout << "PRINT CHECK" << *contact.contactAccess[indexFreeContact][1] << std::endl;
	add_sub_contact("Nick Name : ", &*contact.contactAccess[writeIndex][2]);
	// std::cout << "PRINT CHECK" << *contact.contactAccess[indexFreeContact][2] << std::endl;
	add_sub_contact("Phone Number : ", &*contact.contactAccess[writeIndex][3]);
	// std::cout << "PRINT CHECK" << *contact.contactAccess[indexFreeContact][3] << std::endl;
	add_sub_contact("Secret : ", &*contact.contactAccess[writeIndex][4]);
	// std::cout << "PRINT CHECK" << *contact.contactAccess[indexFreeContact][4] << std::endl;
	
	// do
	// {
	// 	print("First Name : ");
	// 	getline(std::cin, *contact.contactAccess[indexFreeContact][0]);
	// } while (stringIsEmpty(*contact.contactAccess[indexFreeContact][0]));

	// print(*contact.contactAccess[indexFreeContact][0]);
}

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

void	title_print(void)
{
	print_no_endl("|   INDEX  ");
	print_no_endl("| 1st name ");
	print_no_endl("| lastname ");
	print_no_endl("| nick name|");
	// print_no_endl("| phone nb ");
	// print_no_endl("|  secret  |");
	std::cout << std::endl;
}

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

bool	is_valid_index(std::string str)
{
	if (str == "1"
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

bool	is_yes_or_no(std::string str)
{
	if (str == "y"
	or	str == "n")
		return true;
	print_color(RED, "⛔ Wrong input typed ⛔");
	return false;
}
	
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

	if (stringIsEmpty(*contact.contactAccess[0][0]))
		std::cout << RED << "NO CONTACT TO DISPLAY" << RESET << std::endl;
	else
	{
		// Print tab
		for (int i = 0; i < NB_CONTACT; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (!stringIsEmpty(*contact.contactAccess[i][j]))
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
			// ask for index between 1 and 8
			do
			{
				print_color_no_endl(GREEN, "Please choose the index");
				print_no_endl(" (ex: 2) ");
				std::cout << BOLD << YELLOW <<  "-----" << RESET << std::endl;
				getline(std::cin, promptIndex);
			} while (!is_valid_index(promptIndex));

			// takes the index string "1" to "0" then to (int)0
			int indexToDisplay = promptIndex[0] - 1 - 48;

			// print everything on stdout
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
		
		/*
		! need for refactoring big functions
		! check in search printing if the contact already exists, otherwise skip (in valid_index function)
		! As the user for another search
		! fix little colors prints
		! refactor little libft functions
		! refactor big ass functions in subfunctions
		! ET VOILA
		
		*/
		
	}
}

int main(void)
{
	// Instance of contact first
	Contact contact;
	// Instance of phoneBook second
	PhoneBook phoneBook;

	int writeIndex = 0;

	// Declare the main_prompt as 
	std::string main_prompt;
	
	// Empty fill addresses
	assign_adresses(&phoneBook, &contact);

	clear_screen();

	welcoming_printing("PhoneBook 1982");
	while (1)
	{
		please_prompt("");
		
		do
		{
			getline(std::cin, main_prompt);
			if (!valid_prompt(main_prompt))
			{
				please_prompt("error");
			}
		} while (!valid_prompt(main_prompt));
		
		if (main_prompt == "EXIT")
			custom_exit();
		else if (main_prompt == "ADD")
		{
			add_contact(&phoneBook, writeIndex);
			writeIndex++;
			if (writeIndex == 8)
				writeIndex = 0;
		}
		else // SEARCH
			search_contact(&phoneBook);
	}
}