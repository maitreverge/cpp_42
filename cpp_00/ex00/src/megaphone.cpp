/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:55:34 by flverge           #+#    #+#             */
/*   Updated: 2024/05/11 12:08:50 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * @brief Main function for megaphone.cpp
 * If ac == 1 => Outputs "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
 * Otherwise, converts the given parametters in uppercase
 * 
 * @param ac 
 * @param av 
 * @return int 
 */
int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; av[i] != 0; i++)
		{
			for (int j = 0; av[i][j] != 0; j++)
			{
				// Convert to upper each letter before printing it out
				// ! Need to cast it in a char, otherwise it prints out actual ASCII values
				std::cout << (char)std::toupper(av[i][j]);
			}
			// One space between words 
			std::cout << " ";
		}
		// Then back at the line
		std::cout << std::endl;
	}
	// Must return a value in C++ main function
	return 0;
}