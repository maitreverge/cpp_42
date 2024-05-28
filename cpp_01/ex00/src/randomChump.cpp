/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:56:45 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 14:36:14 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Create a new Zombie on the stack.
 * 
 * @param name 
 */
void randomChump( std::string name){
	// Create a new Zombie.
	Zombie newBoi;

	// Pass the name in the setter function
	newBoi.setName(name);
	newBoi.announce();
}