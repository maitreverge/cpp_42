/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:39:35 by flverge           #+#    #+#             */
/*   Updated: 2024/06/12 22:26:47 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

int main( void ){

	ClapTrap pikachu("Pikachu");

	ClapTrap enemy("Miaous");
	clearScreen();

	// for (size_t i = 0; i < 6; i++)
	// 	std::cout << std::endl;
	
	pikachu.printHealthBar(1);
	pikachu.displayChararter();
	return (0);
}