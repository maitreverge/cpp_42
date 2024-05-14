/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:25:28 by flverge           #+#    #+#             */
/*   Updated: 2024/05/14 15:58:32 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void	assign_adresses(PhoneBook *phoneBook, Contact *contact)
{
	for (int i = 0; i < NB_CONTACT ; i++)
	{
		phoneBook->contactAccess[i][0] = &contact->index[i];
		phoneBook->contactAccess[i][1] = &contact->first_name[i];
		phoneBook->contactAccess[i][2] = &contact->last_name[i];
		phoneBook->contactAccess[i][3] = &contact->nick_name[i];
		phoneBook->contactAccess[i][4] = &contact->phone_number[i];
		phoneBook->contactAccess[i][5] = &contact->secret[i];
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

void	add_contact(PhoneBook *ptr, int writeIndex, int displayIndex)
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

	*contact.contactAccess[writeIndex][0] = displayIndex;
	
	add_sub_contact("First Name : ", &*contact.contactAccess[writeIndex][1]);
	// std::cout << "PRINT CHECK" << *contact.contactAccess[indexFreeContact][0] << std::endl;
	add_sub_contact("Last Name : ", &*contact.contactAccess[writeIndex][2]);
	// std::cout << "PRINT CHECK" << *contact.contactAccess[indexFreeContact][1] << std::endl;
	add_sub_contact("Nick Name : ", &*contact.contactAccess[writeIndex][3]);
	// std::cout << "PRINT CHECK" << *contact.contactAccess[indexFreeContact][2] << std::endl;
	add_sub_contact("Phone Number : ", &*contact.contactAccess[writeIndex][4]);
	// std::cout << "PRINT CHECK" << *contact.contactAccess[indexFreeContact][3] << std::endl;
	add_sub_contact("Secret : ", &*contact.contactAccess[writeIndex][5]);
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
		if (i == 4)
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
	print_no_endl("| nick name");
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
		for (int i = 0; i < NB_CONTACT; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (!stringIsEmpty(*contact.contactAccess[i][j]))
				{
					display_line_contact(*contact.contactAccess[i][j]);
					if (j == 3)
					{
						print_no_endl("|");
						std::cout << std::endl;
					}
				}
			}
		}
		print_separators();
	}
}

int main(void)
{
	// Instance of contact first
	Contact contact;
	// Instance of phoneBook second
	PhoneBook phoneBook;

	int writeIndex = 0;
	int displayIndex = 1;

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
			add_contact(&phoneBook, writeIndex, displayIndex);
			writeIndex++;
			displayIndex++;
			if (writeIndex == 8)
				writeIndex = 0;
		}
		else // SEARCH
			search_contact(&phoneBook);
	}
}