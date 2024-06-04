/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:58:15 by flverge           #+#    #+#             */
/*   Updated: 2024/06/04 10:14:07 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

static bool isValidPrompt ( string& str ){
	if (str == "DEBUG"
	or	str == "INFO"
	or	str == "WARNING"
	or	str == "ERROR")
		return true;
	printColor(RED, "⛔ Please enter a valid prompt ⛔");
	printColor(YELLOW, "DEBUG // INFO // WARNING // ERROR");
	return false;
}

int main( void ){
	
	Harl harlVariable;
	
	string promptUser;
	
	clearScreen();

	printColor(GREEN, "Welcome to Harl Program !!");
	printColor(GREEN, "Please enter a message");
	printColor(YELLOW, "DEBUG // INFO // WARNING // ERROR");

	do
	{
		getline(cin, promptUser);
	} while (!isValidPrompt(promptUser));

	harlVariable.complain(promptUser);
	
	return (0);
}