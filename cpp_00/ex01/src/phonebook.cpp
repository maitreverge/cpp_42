/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:29:47 by flverge           #+#    #+#             */
/*   Updated: 2024/05/13 18:42:35 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/**
 * @brief Construct a new Phone Book:: Phone Book object
 * 
 */
PhoneBook::PhoneBook(void)
{
	return ;
}

/**
 * @brief Destroy the Phone Book:: Phone Book object
 * 
 */
PhoneBook::~PhoneBook(void)
{
	return;
}

Contact::Contact(void)
{
	// At the start of execution, fill all the variables with nothing
	for (int i = 0; i < NB_CONTACT; i++)
	{
		this->first_name[i] = "";
		this->last_name[i] = "";
		this->nick_name[i] = "";
		this->phone_number[i] = "";
		this->secret[i] = "";
	}
	return;
}

Contact::~Contact(void)
{
	return;
}



