/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:58:08 by flverge           #+#    #+#             */
/*   Updated: 2024/06/02 14:19:20 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.hpp"

/**
 * @brief Wrapper function to print a message and exit the program.
 * 
 */
static void wrongInput( void ){
	printColor(RED, "⛔ Wrong Arguments ⛔");
	print("Usage : ");
	printColorNoEndl(GREEN, "./sed_is_for_losers   ");
	printColorNoEndl(YELLOW, "\"Target string\"   ");
	printColor(BLUE, "\"String to remplace\"");
	exit(EXIT_FAILURE);
}

int main(int ac, char**av){
	if (ac != 3)
		wrongInput();
	
	string target = av[1];
	string remplace = av[2];
	
	if (target == remplace)
	{
		printColor(RED, "⛔ argv[1] and argv[2] are identical ⛔");
		exit(EXIT_FAILURE);
	}

	
}