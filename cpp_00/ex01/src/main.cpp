/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:25:28 by flverge           #+#    #+#             */
/*   Updated: 2024/05/15 11:53:19 by flverge          ###   ########.fr       */
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
	} while (string_is_empty(*target));
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

	// if (!string_is_empty(*contact.contactAccess[7][0]))
	// 	indexFreeContact = 0;
	// else
	// {
	// 	for (int i = 0; !string_is_empty(*contact.contactAccess[i][0]); i++) // segfault
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
	// } while (string_is_empty(*contact.contactAccess[indexFreeContact][0]));

	// print(*contact.contactAccess[indexFreeContact][0]);
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
		clear_screen();
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