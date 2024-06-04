/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:58:30 by flverge           #+#    #+#             */
/*   Updated: 2024/06/04 10:30:51 by flverge          ###   ########.fr       */
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

int main( int ac, char **av){
	if (ac != 2)
		printUsage();
	
}