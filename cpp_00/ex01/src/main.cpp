/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:08:53 by flverge           #+#    #+#             */
/*   Updated: 2024/05/27 19:38:59 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/**
 * @brief Wrapper function for adding a non empty contact subdetail.
 * if `detail` == 1 : setFirstName
 * if `detail` == 2 : setLastName
 * if `detail` == 3 : setNickName
 * if `detail` == 4 : setPhoneNumber
 * if `detail` == 5 : setSecret
 * 
 * @param contact 
 * @param string 
 * @param detail 
 */
void	addContactDetails( Contact &contact, std::string string, size_t detail )
{
	std::string addPrompt;

	do
	{
		print(string);
		getline(std::cin, addPrompt);
	} while (addPrompt.empty());

	switch (detail)
	{
		case 1:
			contact.setFirstName(addPrompt);
			break;
		case 2:
			contact.setLastName(addPrompt);
			break;
		case 3:
			contact.setNickName(addPrompt);
			break;
		case 4:
			contact.setPhoneNumber(addPrompt);
			break;
		case 5:
			contact.setSecret(addPrompt);
			break;
		default:
			break;
	}
}

Contact	addNewContact( size_t index ){

	Contact newContact;

	std::string addPrompt;
	
	clearScreen();
	welcomePrinting("ADD CONTACT MENU");

	newContact.setIndex(index);
	
	print("Please enter contact details bellow : ");
	
	addContactDetails(newContact, "Enter First Name", 1);
	addContactDetails(newContact, "Enter Last Name", 2);
	addContactDetails(newContact, "Enter Nick Name", 3);
	addContactDetails(newContact, "Enter Phone Number", 4);
	addContactDetails(newContact, "Enter Darkest Secret", 5);

	return newContact;
}

int main( void ){

	Phonebook phonebook;
	std::string menuPrompt;
	size_t index = 0;

	clearScreen();
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
			phonebook.appendNewContact(addNewContact(index), index);
			index++;
			if (index == 9)
				index= 0;
		}
		else if (menuPrompt == "SEARCH")
			phonebook.searchContact();
		else // EXIT
			definiveExit();
	}
	return 0;
}