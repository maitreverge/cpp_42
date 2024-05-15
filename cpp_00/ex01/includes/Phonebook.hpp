/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:28:06 by flverge           #+#    #+#             */
/*   Updated: 2024/05/15 12:49:55 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <cctype>
#include <cstring>


#define NB_CONTACT 8
#define MAX_WIDTH 10


// ANSII colors codes
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

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

void	search_contact(PhoneBook *ptr);

// utils_printing.cpp
void	print(std::string str);
void	print_no_endl(std::string str);
void	print_color(std::string COLOR, std::string str);
void	print_color_no_endl(std::string COLOR, std::string str);
bool	string_is_empty(std::string str);
void	clear_screen(void);
void	custom_exit(void);
bool	valid_prompt(std::string prompt);
void	welcoming_printing(std::string message);
void	please_prompt(std::string message);

#endif // PHONEBOOK_HPP