/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:25:28 by flverge           #+#    #+#             */
/*   Updated: 2024/05/14 13:33:28 by flverge          ###   ########.fr       */
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

void	add_sub_contact(std::string message, std::string target)
{
	do
	{
		print(message);
		getline(std::cin, target);
	} while (stringIsEmpty(target));
}

void	add_contact(PhoneBook *ptr)
{
	PhoneBook contact;

	contact = *ptr;
	
	int indexFreeContact = 0;	
	clear_screen();

	welcoming_printing("ADD Contact Menu");

	print("Please enter contact details bellow : ");

	// finds next free contact
	// ! needs to point to the first one if everything full
	// for (int i = 0; *contact.contactAccess[i][0] != ""; i++)
	for (int i = 0; stringIsEmpty(*contact.contactAccess[i][0]); i++)
		indexFreeContact++;
	
	add_sub_contact("First Name : ", *contact.contactAccess[indexFreeContact][0]);
	add_sub_contact("Last Name : ", *contact.contactAccess[indexFreeContact][1]);
	add_sub_contact("Nick Name : ", *contact.contactAccess[indexFreeContact][2]);
	add_sub_contact("Phone Number : ", *contact.contactAccess[indexFreeContact][3]);
	add_sub_contact("Secret : ", *contact.contactAccess[indexFreeContact][4]);
	
	// do
	// {
	// 	print("First Name : ");
	// 	getline(std::cin, *contact.contactAccess[indexFreeContact][0]);
	// } while (stringIsEmpty(*contact.contactAccess[indexFreeContact][0]));

	// print(*contact.contactAccess[indexFreeContact][0]);
}
	
void	search_contact(PhoneBook *ptr)
{
	PhoneBook contact;

	contact = *ptr;
	
}

int main(void)
{
	// Instance of contact first
	Contact contact;
	// Instance of phoneBook second
	PhoneBook phoneBook;

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
			add_contact(&phoneBook);
		else // SEARCH
			search_contact(&phoneBook);
	}
}