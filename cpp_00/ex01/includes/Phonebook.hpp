/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:28:06 by flverge           #+#    #+#             */
/*   Updated: 2024/05/13 20:04:19 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include <iostream>
#include <string>
#include <cstdlib>


#define NB_CONTACT 8

// colors
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLD    "\033[1m"       /* Bold */

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
	
		std::string *contactAccess[NB_CONTACT][5];
		
};

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		std::string first_name[NB_CONTACT];
		std::string last_name[NB_CONTACT];
		std::string nick_name[NB_CONTACT];
		std::string phone_number[NB_CONTACT]; // no letters
		std::string secret[NB_CONTACT];
		
};

void	custom_exit(void);
void	welcoming_printing(void);
void	please_prompt(std::string message);
bool	valid_prompt(std::string prompt);



#endif // PHONEBOOK_HPP