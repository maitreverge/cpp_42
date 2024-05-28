/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:56:38 by flverge           #+#    #+#             */
/*   Updated: 2024/05/28 14:32:04 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(   /*fuck la norme*/           void ){
	// RandomChump work on the stack
	randomChump("Tom");

	// Because newZombie works on the heap, it needs freeing
	Zombie* babyBoi = newZombie("Jerry");
	
	babyBoi->announce();

	delete babyBoi;
	
	return (0);
}