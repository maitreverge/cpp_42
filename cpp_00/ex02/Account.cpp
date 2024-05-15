/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:42:55 by flverge           #+#    #+#             */
/*   Updated: 2024/05/15 14:47:54 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <chrono>

/**
 * @brief 
 * @brief Construct a new Account:: Account object
 * 
 * @param initial_deposit 
 */
Account::Account( int initial_deposit )
{
	
}

/**
 * @brief Destroy the Account:: Account object
 * 
 */
Account::~Account( void )
{
	return;
}

/**
 * @brief Displays the timestamp under the `[YYYYMMDD_HHMMSS]` format
 * 
 */
static void	displayTimestamp( void )
{
	// Get the current time as a time_t object
	std::time_t time_t_stamp = std::time(NULL);

	// Convert the time_t object to a tm structure representing local time
	std::tm* tm = std::localtime(&time_t_stamp);

	char buffer[16];

	// Format the time according to the format string provided
	// %Y represents the year, %m the month, %d the day, %H the hour, %M the minute, and %S the second
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", tm);

	std::cout << "[" << buffer << "] " << std::endl;
}