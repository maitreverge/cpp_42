/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:08:43 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 11:52:13 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Contact::Contact ( void ){
	this->_index = 0;
	this->setFirstName("");
	this->setLastName("");
	this->setNickName("");
	this->setPhoneNumber("");
	this->setSecret("");
	return;
}

Contact::~Contact( void ){}

size_t Contact::getIndex( void ) const {
	return this->_index;
}

void Contact::setIndex ( size_t index ){
	this->_index = index;
}

std::string Contact::getFirstName( void ) const {
	return this->_firstName;
}

void Contact::setFirstName( std::string input ){
	this->_firstName = input;
}

std::string Contact::getLastName( void ) const {
	return this->_lastName;
}

void Contact::setLastName( std::string input ){
	this->_lastName = input;
}

std::string Contact::getNickName( void ) const {
	return this->_nickName;
}

void Contact::setNickName( std::string input ){
	this->_nickName = input;
}

std::string Contact::getPhoneNumber( void ) const {
	return this->_phoneNumber;
}

void Contact::setPhoneNumber( std::string input ){
	this->_phoneNumber = input;
}

std::string Contact::getSecret( void ) const {
	return this->_secret;
}

void Contact::setSecret( std::string input ){
	this->_secret = input;
}