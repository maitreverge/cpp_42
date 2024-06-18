/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_functions.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:57:20 by flverge           #+#    #+#             */
/*   Updated: 2024/06/18 13:48:46 by flverge          ###   ########.fr       */
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
	
	if (input == "1" // ATTACK
	or	input == "2" // HEAL
	or	input == "3" // GUARD GATE FROM SCAV
	or	input == "4" // HIGH FIVE FROM FRAG
	or	input == "5" // WHOAMI FROM DIAMOND
	or	input == "6") // EXIT
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
	
	printNoEndl("[3] ");
	printColorNoEndl( HIGH_INTENSITY_GREEN, player.getName());
	printColor( HIGH_INTENSITY_YELLOW, "  GUARD GATE ");

	printNoEndl("[4] ");
	printColorNoEndl( HIGH_INTENSITY_GREEN, player.getName());
	printColor( HIGH_INTENSITY_YELLOW, "  SAY HI");

	printNoEndl("[5] ");
	printColorNoEndl( HIGH_INTENSITY_GREEN, player.getName());
	printColor( HIGH_INTENSITY_YELLOW, "  DISPLAYS IDENTITY");
	
	printColor(RED, "[6] EXIT");
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