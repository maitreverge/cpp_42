/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:08:40 by flverge           #+#    #+#             */
/*   Updated: 2024/05/27 19:13:05 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

#include "Contact.hpp"
#include "libcpp.hpp"

#define NB_CONTACT 8

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

class Phonebook
{
	public:
		Phonebook( void );
		~Phonebook( void );
		void	appendNewContact( Contact newContact, size_t index);
		void	searchContact( void ) const;
		void	printAllContacts( void ) const;
		void	printDetailsContact( std::string toPrint ) const;
	private:
		Contact accessContact[8];
};

#endif // __PHONEBOOK_HPP__