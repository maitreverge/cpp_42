/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:56:43 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 14:35:36 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Allocate a new Zombie on the heap.
 * 
 * @param name 
 * @return Zombie* 
 */
Zombie* newZombie( std::string name){
	Zombie* newBabyBoi;

	newBabyBoi = new Zombie;

	newBabyBoi->setName(name);	

	return newBabyBoi;
}