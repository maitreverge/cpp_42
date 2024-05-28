/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:11 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 15:54:27 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

void stringToInt( const std::string& str, int& result ){
    std::istringstream iss(str);
    iss >> result;

    // Check if the entire string was parsed and no errors occurred
    if (iss.fail() or !iss.eof()) {
		std::cerr << "Error from stringToInt" << std::endl;
		std::exit(EXIT_FAILURE);
    }
}

int main( int ac, char **av ){
	
	if (ac != 2)
	{
		std::cout << "Usage : ./moar_brainz" << RED << " <nb>" << RESET << std::endl;
		return 1;
	}
	
	Zombie* bigHord;
	
	int		nbZombies;
	
	stringToInt(av[1], nbZombies);

	bigHord = zombieHorde(nbZombies, "Marc");

	// announce loop
	for (int i = 0; i < nbZombies; i++)
	{
		bigHord[i].announce();
	}

	// Merci Bjarne Stroustrup
	delete[] bigHord;

	return 0;
}