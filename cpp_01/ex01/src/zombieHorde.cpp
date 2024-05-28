/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:57:16 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 15:29:00 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/**
 * @brief Allocate in a single shot every zombies.
 * 
 * @param N 
 * @param name 
 * @return Zombie* 
 */
Zombie* zombieHorde( int N, std::string name ){
	Zombie* hord = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		hord[i].setName(name);
	}
	return hord;
}