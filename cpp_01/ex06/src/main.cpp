/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:58:30 by flverge           #+#    #+#             */
/*   Updated: 2024/06/04 11:41:52 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

static void printUsage( void ){
	printColor(RED, "⛔ Wrong Usage⛔ ");
	printNoEndl("Usage :   ");
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
	
	Harl thisIsHarl(av[1]);
	
	checkValidString(thisIsHarl.getMessage());

	// No break, as asked in the subject,
	// the first corrent occurence will trigger all the others ones.
	switch (thisIsHarl.getMessage()[0])
	{
		case 'D': // debug
			// Accessing, in the instance class, the class instance pointer
			(thisIsHarl.*(thisIsHarl.ptrDebug))();
		case 'I': // info
			(thisIsHarl.*(thisIsHarl.ptrInfo))();
		case 'W': // warning 
			(thisIsHarl.*(thisIsHarl.ptrWarning))();
		case 'E': // error
			(thisIsHarl.*(thisIsHarl.ptrError))();
		default: // kind of useless, as I already filtered before
			break;
	}

	return 0;
}