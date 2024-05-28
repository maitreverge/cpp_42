/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:09:00 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 09:08:31 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/**
 * @brief Checks if the string is a valid index (1-8)
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool	isValidIndex( std::string str ){
	if (str == "1"
	or	str == "2"
	or	str == "3"
	or	str == "4"
	or	str == "5"
	or	str == "6"
	or	str == "7"
	or	str == "8")
		return true;
	return false;
}

/**
 * @brief Print `+----------+`
 * 
 */
void	print_separators(void){
	for (int i = 0; i < 4; i++)
	{
		printNoEndl("+----------");
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
void	title_print(void){
	printNoEndl("|   INDEX  ");
	printNoEndl("| 1st name ");
	printNoEndl("| lastname ");
	printNoEndl("| nick name|");
	std::cout << std::endl;
}

Phonebook::Phonebook( void ) {}

Phonebook::~Phonebook( void ) {}

void	Phonebook::appendNewContact( Contact newContact, size_t index ){
	this->accessContact[index] = newContact;
}

/**
 * @brief Print a string with a dot if the string is too long (10 characters)
 * 
 * @param toPrint 
 */
void	Phonebook::printDetailsContact( std::string toPrint ) const{
	size_t lenString = toPrint.size();
	
	printNoEndl("|");
	
	if (lenString > 10) // print with .
	{
		for (size_t i = 0; i < 9; i++) // print from 1st to 9th letter
			std::cout << toPrint[i];
		printNoEndl(".");
	}
	else // space printing before
	{
		for (size_t i = 0; i < 10 - lenString; i++)
			printNoEndl(" ");
		printNoEndl(toPrint);
	}
	
}

/**
 * @brief Print all contacts in the phonebook.
 * 
 */
void	Phonebook::printAllContacts ( void ) const{
	// need to print index, first name, last name and nickname
	for (size_t i = 0; i < NB_CONTACT; i++)
	{
		if (!this->accessContact[i].getFirstName().empty())
		{
			// print the index
			printNoEndl("|         ");
			std::cout << i + 1;
			
			// print subdetails
			printDetailsContact(this->accessContact[i].getFirstName());
			printDetailsContact(this->accessContact[i].getLastName());
			printDetailsContact(this->accessContact[i].getNickName());
			printNoEndl("|");
			
			// Prints a new line and a +----+ line separator
			std::cout << std::endl;
			print_separators();
		}
	}
}

void	Phonebook::searchContact( void ) const{
	clearScreen();
	welcomePrinting("SEARCH CONTACT MENU");

	print_separators();
	title_print();
	print_separators();
	
	if (this->accessContact[0].getFirstName().empty())
		std::cout << RED << "NO CONTACT TO DISPLAY" << RESET << std::endl;
	else
	{
		printAllContacts();
		
		std::string searchPrompt;

		do
		{
			printColor(YELLOW, "Do you want to display a specific contact's details ?"); // orthographe ??
			printColor(GREEN, "(y/n)");
			getline(std::cin, searchPrompt);
		} while (!(searchPrompt == "y" or searchPrompt == "n"));

		if (searchPrompt == "y")
		{
			do
			{
				printColor(YELLOW, "Please enter a valid index (1-8)");
				getline(std::cin, searchPrompt);
			} while (!isValidIndex(searchPrompt));
			
			int indexPrinting;

			// Convert and decrement so Index "1" become 0
			stringToInt(searchPrompt, indexPrinting); indexPrinting--;

			if (this->accessContact[indexPrinting].getFirstName().empty())
				printColor(RED, "Selected Contact is Empty, back to main menu");
			else
			{
				// Printing detailled contact
				print("First Name :");
				printColor(CYAN, this->accessContact[indexPrinting].getFirstName());
				print("Last Name :");
				printColor(CYAN, this->accessContact[indexPrinting].getLastName());
				print("Nick Name :");
				printColor(CYAN, this->accessContact[indexPrinting].getNickName());
				print("Phone Number :");
				printColor(CYAN, this->accessContact[indexPrinting].getPhoneNumber());
				print("Darkest Secret :");
				printColor(CYAN, this->accessContact[indexPrinting].getSecret());
			}
		}
		else // "n" answer
		{
			clearScreen();
			return;
		}
	}
}
