/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:08:43 by flverge           #+#    #+#             */
/*   Updated: 2024/05/27 10:32:32 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/**
 * @brief Construct a new Contact:: Contact object
 * 
 */
Contact::Contact ( void ) {
	return;
}

/**
 * @brief Destroy the Contact:: Contact object
 * 
 */
Contact::~Contact( void ) {
	return;
}

/**
 * @brief _firstName getter function
 * 
 * @return std::string 
 */
std::string Contact::getFirstName( void ) const {
	return this->_firstName;
}

/**
 * @brief _firstName setter function
 * 
 * @param input 
 */
void Contact::setFirstName( std::string input ) {
	this->_firstName = input;
}

std::string Contact::getLastName( void ) const {
	return this->_lastName;
}

void Contact::setLastName( std::string input ) {
	this->_lastName = input;
}

std::string Contact::getNickName( void ) const {
	return this->_nickName;
}

void Contact::setNickName( std::string input ) {
	this->_nickName = input;
}

std::string Contact::getPhoneNumber( void ) const {
	return this->_phoneNumber;
}

void Contact::setPhoneNumber( std::string input ) {
	this->_phoneNumber = input;
}

std::string Contact::getSecret( void ) const {
	return this->_secret;
}

void Contact::setSecret( std::string input ) {
	this->_secret = input;
}