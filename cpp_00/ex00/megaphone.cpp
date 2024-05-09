/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:55:34 by flverge           #+#    #+#             */
/*   Updated: 2024/05/09 13:03:49 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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
				// Convert to upper each letter before printing it out.
				std::cout << (char)std::toupper(av[i][j]);
				// Need to cast it in a char, otherwise it prints out actual ASCII values.
			}
			// One space between words 
			std::cout << " ";
		}
		// Then back at the line
		std::cout << std::endl;
	}
	// must return a value in c++ main
	return 0;
}