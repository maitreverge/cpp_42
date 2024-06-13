/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:39:35 by flverge           #+#    #+#             */
/*   Updated: 2024/06/13 15:59:08 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

static void printUsageCharacter( void ){

	printColor(YELLOW, "SELECT YOUR PLAYER");
	print("[1] PIKACHU");
	print("[2] SHREK");
	printColor(RED, "[3] EXIT");
}

static bool validPromptCharacter( string input ){
	
	if (input == "1"
	or	input == "2"
	or	input == "3")
		return true;
	return false;
}

void printUsageActions( ClapTrap& player, ClapTrap& enemy ){
	
	printColor(YELLOW, "SELECT YOUR ACTION");
	printNoEndl("[1] ATTACK   ");
	printColor( HIGH_INTENSITY_RED, enemy.getName());
	printNoEndl("[2] HEAL     ");
	printColor( HIGH_INTENSITY_GREEN, player.getName());
	printColor(RED, "[3] EXIT");
}

static void characterTakesAction( ClapTrap& player, ClapTrap& enemy ){
	
	// Print which player we are actually playing
	printColor(UNDERLINE_GREEN, player.getName());
	
	string userPrompt;

	do
	{
		printUsageActions(player, enemy);
		printColorNoEndl(BOLD_YELLOW, "$ > ");
		getline(cin, userPrompt);
	} while (!validPromptCharacter( userPrompt ));

	switch (userPrompt[0])
	{
		case '1': // ATTACK
			player.attack(enemy.getName());
			enemy.takeDamage(1);
			break;
		case '2': // HEAL
			player.beRepaired(1);
			break;
		case '3': // exit
			break;
			// clearScreen();
			// customExit("Battle is Over");
	}
}

static void startBattle( ClapTrap& pikachu, ClapTrap& shrek, char choice){

	switch (choice)
	{
		case '1': // pikachu
			characterTakesAction(pikachu, shrek);
			break;
		case '2': // shrek
			characterTakesAction(shrek, pikachu);
			break;
		case '3': // exit
			clearScreen();
			customExit("Battle is Over");
			break;
	}
}

int main( void ){

	ClapTrap pikachu("Pikachu");

	ClapTrap shrek("Shrek");
	
	clearScreen();

	// pikachu.takeDamage(1);
	// pikachu.beRepaired(1);
	
	string userPrompt;
	while (true){
		
		shrek.printHealthBar(1);
		shrek.displayShrek();
		for (size_t i = 0; i < 4; i++)
			std::cout << std::endl;
		pikachu.printHealthBar();
		pikachu.displayPikachu();

		// ! STEP ONE : SELECT CHARACTER WHICH DO THE ACTION
		do
		{
			printUsageCharacter();
			printColorNoEndl(BOLD_YELLOW, "$ > ");
			getline(cin, userPrompt);
		} while (!validPromptCharacter( userPrompt ));
		
		startBattle(pikachu, shrek, userPrompt[0]);
		
	}
	return (0);
}