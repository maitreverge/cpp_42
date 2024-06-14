/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:39:35 by flverge           #+#    #+#             */
/*   Updated: 2024/06/14 14:55:50 by flverge          ###   ########.fr       */
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
	printColorNoEndl( HIGH_INTENSITY_RED, enemy.getName());
	printColor( HIGH_INTENSITY_YELLOW, "   (Cost 1 🔋)");
	printNoEndl("[2] HEAL     ");
	printColorNoEndl( HIGH_INTENSITY_GREEN, player.getName());
	printColor( HIGH_INTENSITY_YELLOW, "   (Cost 1 🔋)");
	printColor(RED, "[3] EXIT");
}


static void displayBothPlayers( ClapTrap& enemy, ClapTrap& player){

	enemy.printHealthBar(1);
	enemy.displayShrek();
	for (size_t i = 0; i < 4; i++)
		std::cout << std::endl;
	player.printHealthBar();
	player.displayPikachu();
}

static void characterTakesAction( ClapTrap& player, ClapTrap& enemy, int sw = 0){
	
	clearScreen();
	
	// Displays the correct stats bars depending which character is plugged as `player` or `enemy`
	!sw ? displayBothPlayers(enemy, player) : displayBothPlayers(player, enemy);

	// Checks if the selected player is alive, exit if so.
	if (!player.getHitPoints())
		{printColor(HIGH_INTENSITY_RED ,player.getName() + " is already dead, can't do anything 💀"); return;}
	
	// Print which player we are actually playing
	printColor(UNDERLINE_GREEN, "SELECTED PLAYER : " + player.getName() + "\n");
	
	string userPrompt;
	
	// User prompt 1 / 2 or 3
	do
	{
		printUsageActions(player, enemy);
		printColorNoEndl(BOLD_YELLOW, "$ > ");
		getline(cin, userPrompt);
	} while (!validPromptCharacter( userPrompt ));

	switch (userPrompt[0])
	{
		case '1': // ATTACK
			if (!player.getAttackDamage()){
				if (player.getEnergyPoints())
					player.updateEnergyPoints(-1); // Attacking cost energy despite having no attackDamage
				player.printFunctionMessage(ClapTrap::NO_DAMAGE, ""); 
			}
			else if (!player.getEnergyPoints())
				player.printFunctionMessage(ClapTrap::NO_ENERGY, "");
			else if (!enemy.getHitPoints())
				enemy.printFunctionMessage(ClapTrap::NO_HEALTH, "");
			else { // actual attacking condition
				player.attack(enemy.getName());
				enemy.takeDamage(player.getAttackDamage());
			}
			break;
		case '2': // HEAL
			player.beRepaired(1);
			break;
		case '3': // EXIT
			break;
		default: // just to be safe
			break;
	}
}

static void startBattle( ClapTrap& pikachu, ClapTrap& shrek, char choice){
	
	switch (choice)
	{
		case '1': // pikachu
			characterTakesAction(pikachu, shrek);
			break;
		case '2': // shrek
			characterTakesAction(shrek, pikachu, 1);
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

	sleep(2);
	

	string userPrompt;
	while (true){
		
		// Prints and wait 2 seconds.
		printColor(BACKGROUND_HIGH_INTENSITY_CYAN, "LOADING CHARACTERS"); sleep(2);
		
		clearScreen();

		displayBothPlayers(shrek, pikachu);

		// * USER is prompted to choose the character
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