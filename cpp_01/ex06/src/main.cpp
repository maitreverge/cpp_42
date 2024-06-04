/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:58:30 by flverge           #+#    #+#             */
/*   Updated: 2024/06/04 11:27:09 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

static void printUsage( void ){
	printColor(RED, "⛔ Wrong Usage⛔ ");
	printNoEndl("Usage :");
	printColorNoEndl(GREEN, "./harlFilter     ");
	printColor(YELLOW, "\"MESSAGE\"");
	exit(EXIT_FAILURE);
}

static void checkValidString( string str ){
	if (!(str == "DEBUG"
	or	str == "INFO"
	or	str == "WARNING"
	or	str == "ERROR")){
		printColor(YELLOW, "Probably complaining about insignificant problems");
		exit(EXIT_FAILURE);
	}
}

int main( int ac, char **av){
	if (ac != 2)
		printUsage();
	
	clearScreen();
	
	Harl thisIsHarl(av[1]);
	
	checkValidString(thisIsHarl.getMessage());

	switch (thisIsHarl.getMessage()[0])
	{
		case 'D': // debug
			(thisIsHarl.*ptrDebug());
		case 'I': // info
		case 'W': // warning 
		case 'E': // error
		
		default:
			break;
	}

	return 0;
}