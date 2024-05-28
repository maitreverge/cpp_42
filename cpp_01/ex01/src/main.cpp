/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:11 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 19:42:12 by flverge          ###   ########.fr       */
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
		std::cout << "Usage : "<< YELLOW << "./moar_brainz" << RED << " <nb_of_zombies>" << RESET << std::endl;
		return 1;
	}
	
	Zombie* bigHord;
	
	int		nbZombies;
	
	stringToInt(av[1], nbZombies);

	if (nbZombies <= 0)
	{
		std::cout << RED << "Number of Zombies can't be less than 1" << RESET << std::endl;
		std::exit(EXIT_FAILURE);
	}

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