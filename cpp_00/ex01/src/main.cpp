/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:25:28 by flverge           #+#    #+#             */
/*   Updated: 2024/05/16 10:26:19 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/**
 * @brief Assign the string pointer from Phonebook class to Contact class
 * 
 * @param phoneBook 
 * @param contact 
 */
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

/**
 * @brief Simple `do...while` statement for getting a non empty contact detail
 * 
 * @param message 
 * @param target 
 */
void	add_sub_contact(std::string message, std::string *target)
{
	do
	{
		print(message);
		getline(std::cin, *target);
	} while (string_is_empty(*target));
}

/**
 * @brief Global adding contact function
 * 
 * @param ptr 
 * @param writeIndex 
 */
void	add_contact(PhoneBook *ptr, int writeIndex)
{
	PhoneBook contact;

	contact = *ptr;
	
	clear_screen();

	welcoming_printing("ADD Contact Menu");

	print("Please enter contact details bellow : ");

	add_sub_contact("First Name : ", &*contact.contactAccess[writeIndex][0]);
	add_sub_contact("Last Name : ", &*contact.contactAccess[writeIndex][1]);
	add_sub_contact("Nick Name : ", &*contact.contactAccess[writeIndex][2]);
	add_sub_contact("Phone Number : ", &*contact.contactAccess[writeIndex][3]);
	add_sub_contact("Secret : ", &*contact.contactAccess[writeIndex][4]);
	
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
		
		// Asks for either `ADD`, `SEARCH` or `EXIT`
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

/*
! TO FIX : visibility of classes
! EDGE CASE : typing index 9 or shit
*/