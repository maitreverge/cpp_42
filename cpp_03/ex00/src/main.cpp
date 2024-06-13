/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:39:35 by flverge           #+#    #+#             */
/*   Updated: 2024/06/13 12:10:30 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main( void ){

	ClapTrap pikachu("Pikachu");

	ClapTrap shrek("Shrek");
	
	clearScreen();

	
	shrek.printHealthBar(1);
	shrek.displayShrek();
	for (size_t i = 0; i < 4; i++)
		std::cout << std::endl;
	pikachu.printHealthBar();
	pikachu.displayPikachu();
	return (0);
}