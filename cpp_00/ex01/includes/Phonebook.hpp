/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:08:40 by flverge           #+#    #+#             */
/*   Updated: 2024/05/27 10:38:01 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include <iostream>
#include <string>

#include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook( void );
		~Phonebook( void );
		Contact accessContact[8];
	private:
	
	
};





#endif // __PHONEBOOK_HPP__