/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:39:35 by flverge           #+#    #+#             */
/*   Updated: 2024/06/12 19:47:59 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

void	printHealthBar( ClapTrap& pokemon ){
	
	// 💚 💛 ❤️ 💔
	
}

int main( void ){

	ClapTrap pikachu("Pikachu");

	ClapTrap miaous("Miaous");
	clearScreen();

	for (size_t i = 0; i < 6; i++)
		std::cout << std::endl;
	
	pikachu.takeDamage(1);
	pikachu.takeDamage(1);
	pikachu.takeDamage(1);
	pikachu.takeDamage(1);
	pikachu.takeDamage(1);
	pikachu.takeDamage(1);
	pikachu.takeDamage(1);
	pikachu.takeDamage(1);
	pikachu.takeDamage(1);
	pikachu.takeDamage(1);
	pikachu.printHealthBar();
	return (0);
}