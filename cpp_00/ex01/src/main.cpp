/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:25:28 by flverge           #+#    #+#             */
/*   Updated: 2024/05/13 19:45:09 by flverge          ###   ########.fr       */
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

int main(void)
{
	// Instance of contact first
	Contact contact;
	// Instance of phoneBook second
	PhoneBook phoneBook;

	// Declare the main_prompt as 
	std::string main_prompt = 0;
	

	assign_adresses(&phoneBook, &contact);


	welcoming_printing();
	
	while (1)
	{
		// Print the 3 choices
		please_prompt("");
		
		do
		{
			getline(std::cin, main_prompt);
			if (!valid_prompt(main_prompt))
				please_prompt("error");
				
		} while (!valid_prompt(main_prompt));
		
		switch (main_prompt)
		{
			case "EXIT":
				custom_exit();
			case "ADD":
				break;
		}
		
	}
	
}