/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:39:35 by flverge           #+#    #+#             */
/*   Updated: 2024/06/14 10:41:22 by flverge          ###   ########.fr       */
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

static void characterTakesAction( ClapTrap& player, ClapTrap& enemy ){
	
	clearScreen();
	displayBothPlayers(enemy, player);
	// Print which player we are actually playing
	printColor(UNDERLINE_GREEN, "SELECTED PLAYER : "+player.getName()+"\n");
	
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
			if (player.getAttackDamage()){
				player.attack(enemy.getName());
				enemy.takeDamage(1);
			}
			else
				cout << HIGH_INTENSITY_RED << player.getName() << RESET << " can't make any damage !" << endl;

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
	

	string userPrompt;
	while (true){
		
		printColor(BACKGROUND_HIGH_INTENSITY_CYAN, "LOADING CHARACTERS"); sleep(2);
		clearScreen();

		displayBothPlayers(shrek, pikachu);

		// ! STEP ONE : SELECT CHARACTER WHICH DO THE ACTION
		do
		{
			printUsageCharacter();
			printColorNoEndl(BOLD_YELLOW, "$ > ");
			getline(cin, userPrompt);
		} while (!validPromptCharacter( userPrompt ));
		// displayBothPlayers(shrek, pikachu);
		
		startBattle(pikachu, shrek, userPrompt[0]);
		
	}
	return (0);
}