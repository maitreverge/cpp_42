/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_functions.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:57:20 by flverge           #+#    #+#             */
/*   Updated: 2024/06/15 11:17:41 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

void printUsageCharacter( void ){

	printColor(YELLOW, "SELECT YOUR PLAYER");
	print("[1] PIKACHU");
	print("[2] SHREK");
	printColor(RED, "[3] EXIT");
}

bool validPromptCharacter( string input ){
	
	if (input == "1"
	or	input == "2"
	or	input == "3")
		return true;
	return false;
}

void printUsageActions( ClapTrap& player, ClapTrap& enemy ){
	
	printColor(YELLOW, "SELECT YOUR ACTION");
	printNoEndl("[1] ATTACK   ");
	printColorNoEndl( HIGH_INTENSITY_RED, enemy.getName());
	printColor( HIGH_INTENSITY_YELLOW, "   (Cost 1 🔋)");
	printNoEndl("[2] HEAL     ");
	printColorNoEndl( HIGH_INTENSITY_GREEN, player.getName());
	printColor( HIGH_INTENSITY_YELLOW, "   (Cost 1 🔋)");
	printColor(RED, "[3] EXIT");
}


void displayBothPlayers( ClapTrap& enemy, ClapTrap& player ){

	enemy.printStats(1);
	enemy.displayShrek();
	for (size_t i = 0; i < 4; i++)
		std::cout << std::endl;
	player.printStats();
	player.displayPikachu();
}

/**
 * @brief Wrapper function for right alignment of characters stats.
 * 
 */
void rightAlign( void ){
	
	for (size_t i = 0; i < 55; i++)
		printNoEndl(" ");
} 