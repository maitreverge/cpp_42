/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:08:36 by flverge           #+#    #+#             */
/*   Updated: 2024/05/27 10:29:14 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

class Contact
{
	public:
		Contact( void );
		~Contact( void );

		// Getter and setter for first_name
		std::string getFirstName ( void ) const;
		void setFirstName ( std::string input );
		
		// Getter and setter for last_name
		std::string getLastName ( void ) const;
		void setLastName ( std::string input );
		
		// Getter and setter for nick_name
		std::string getNickName ( void ) const;
		void setNickName ( std::string input );
		
		// Getter and setter for phoneNumber
		std::string getPhoneNumber ( void ) const;
		void setPhoneNumber ( std::string input );
		
		// Getter and setter for secret
		std::string getSecret ( void ) const;
		void setSecret ( std::string input );

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _secret;
};

#endif // __CONTACT_HPP__